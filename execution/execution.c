/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:16:12 by asyed             #+#    #+#             */
/*   Updated: 2018/04/03 00:30:47 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>

t_environ	*g_environ;

struct s_ophandlers	op_handlers[] = {
	{&op_pipe_check, &op_pipe_exec},
	{&op_or_check, &op_or_exec},
	{&op_and_check, &op_and_exec},
	{NULL, NULL},
};

int		run_operation(t_ast *curr, uint8_t wait, __attribute__((unused)) t_environ *environ)
{
	pid_t	pid;
	int 	res;

	if (!curr || *(curr->type) == operator)
		return (-1);
	if ((pid = fork()) == -1)
		return (-1);
	if (pid == 0)
	{
		if (handle_redirection(curr))
			exit(EXIT_FAILURE);
		printf("[In: %d, Out: %d, Err: %d]\n", *(curr->p_info->stdin), *(curr->p_info->stdout), *(curr->p_info->stderr));
		dup2(*(curr->p_info->stdin), STDIN_FILENO);
		dup2(*(curr->p_info->stdout), STDOUT_FILENO);
		dup2(*(curr->p_info->stderr), STDERR_FILENO);
		execvP(*(curr->token), getenv("PATH"), curr->token);
		exit(EXIT_FAILURE);
	}
	if (wait)
	{
		waitpid(pid, &res, 0);
		if (!res)
			return (EXIT_SUCCESS);
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static inline __attribute__((always_inline)) void	*init_process(void)
{
	t_process	*new;

	if (!(new = ft_memalloc(sizeof(t_process))))
		return (NULL);
	else if (!(new->stdin = ft_memalloc(sizeof(int))))
	{
		free(new);
	}
	else if (!(new->stderr = ft_memalloc(sizeof(int))))
	{
		free(new);
		free(new->stdin);
	}
	else if (!(new->stdout = ft_memalloc(sizeof(int) * 2)))
	{
		free(new);
		free(new->stdin);
		free(new->stderr);
	}
	else if (!(new->comm = ft_memalloc(sizeof(int) * 2)))
	{
		free(new);
		free(new->stdin);
		free(new->stderr);
		free(new->stdout);
	}
	return (NULL);
}

void	build_leafs(t_ast *curr)
{
	t_process *info;

	if (!(info = init_process()))
		return ;
	*(info->stdin) = *(curr->p_info->stdin);
	*(info->stdout) = curr->p_info->comm[1];
	*(info->stderr) = *(curr->p_info->stderr);
	curr->left_child->p_info = info;
	if (!(info = init_process()))
		return ;
	*(info->stdin) = curr->p_info->comm[0];
	*(info->stdout) = curr->p_info->stdout[1];
	*(info->stderr) = *(curr->p_info->stderr);
	curr->right_child->p_info = info;
}

void	pipe_carry(t_ast *prev, t_ast *curr)
{
	int fds[2];

	if (!curr)
		return ;
	if (!curr->p_info && !(curr->p_info = init_process()))
		return ;
	*(curr->p_info->stdin) = (prev ? *(prev->p_info->stdout) : STDIN_FILENO);
	pipe(fds);
	memcpy(curr->p_info->comm, fds, sizeof(int) * 2);
	pipe(fds);
	if (!(curr->right_child->right_child)) //Right child should *ALWAYS* be allocated
	{
		fds[0] = STDOUT_FILENO;
		fds[1] = STDOUT_FILENO;
	}
	memcpy(curr->p_info->stdout, fds, sizeof(int) * 2);
	*(curr->p_info->stderr) = STDERR_FILENO;
	if (curr->left_child && curr->right_child)
		build_leafs(curr);
}

void	build_default(t_ast *curr)
{
	t_process *info;

	if (!curr || *(curr->type) == operator)
		return ;
	if (!(info = init_process()))
		return ;
	*(info->stdin) = STDIN_FILENO;
	*(info->stdout) = STDOUT_FILENO;
	*(info->stderr) = STDERR_FILENO;
	curr->p_info = info;
}

/* 
** The program should read the AST operation node
** Left:
** 	-> stdin = ASTOP->stdin;
**	-> stdout = ASTOP->comm[1];
** Right:
**  -> stdin = ASTOP->comm[0];
**	-> stdout = ASTOP->stdout[1];
**
** Leafs communicate on single INT pointers a/k/a:
** 	-> stdout = curr->p_info->stdout[0];
*/

int		build_info(t_ast *prev, t_ast *curr, t_environ *environ)
{
	if (!curr)
		return (-1);
	if (*(curr->type) == operator)
	{
		if (!strcmp(*(curr->token), "|"))
			pipe_carry(prev, curr);
		else
		{
			build_default(curr->left_child);
			build_default(curr->right_child);
		}
	}
	else if (!prev)
	{
		build_default(curr);
		run_operation(curr, 0, environ);
	}
	build_info(curr, curr->right_child, environ);
	return (0);
}

int		run_tree(t_ast *curr, t_environ *environ)
{
	int	i;

	if (!curr || !curr->left_child)
		return (0);
	if (*(curr->type) == operator)
	{
		i = 0;
		while (op_handlers[i].check)
		{
			if (!op_handlers[i].check(*(curr->token)))
				return (op_handlers[i].exec(curr, environ));
			i++;
		}
	}
	return (EXIT_FAILURE);
}

int		run_forest(t_ast **asts, t_environ *environ)
{
	int	i;

	i = 0;
	while (asts[i])
	{
		if (build_info(NULL, asts[i], environ))
			return (-1);
		if (run_tree(asts[i], environ))
			return (-1);
		return (255);
		i++;
	}
	return (0);
}
