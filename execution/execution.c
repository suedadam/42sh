/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:16:12 by asyed             #+#    #+#             */
/*   Updated: 2018/03/29 22:03:13 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>

struct s_ophandlers	op_handlers[] = {
	{&op_pipe_check, &op_pipe_exec},
	{&op_or_check, &op_or_exec},
	{&op_and_check, &op_and_exec},
	{NULL, NULL},
};

int		run_operation(t_ast *curr, uint8_t wait)
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

void	build_leafs(t_ast *curr)
{
	t_process *info;

	if (!(info = ft_memalloc(sizeof(t_process))))
		return ;
	if (!(info->stdin = ft_memalloc(sizeof(int)))
		|| !(info->stderr = ft_memalloc(sizeof(int))))
		return ;
	*(info->stdin) = *(curr->p_info->stdin);
	if (!(info->stdout = ft_memalloc(sizeof(int))))
		return ;
	*(info->stdout) = curr->p_info->comm[1];
	curr->left_child->p_info = info;
	if (!(info = ft_memalloc(sizeof(t_process))))
		return ;
	if (!(info->stdin = ft_memalloc(sizeof(int)))
		|| !(info->stderr = ft_memalloc(sizeof(int))))
		return ;
	*(info->stdin) = curr->p_info->comm[0];
	if (!(info->stdout = ft_memalloc(sizeof(int))))
		return ;
	*(info->stdout) = curr->p_info->stdout[1];
	curr->right_child->p_info = info;
}

void	pipe_carry(t_ast *prev, t_ast *curr)
{
	int fds[2];

	if (!curr)
		return ;
	if (!curr->p_info && !(curr->p_info = ft_memalloc(sizeof(t_process))))
		return ;
	if (!prev)
	{
		curr->p_info->stdin = ft_memalloc(sizeof(int));
		*(curr->p_info->stdin) = STDIN_FILENO;
	}
	pipe(fds);
	curr->p_info->comm = ft_memalloc(sizeof(int) * 2);
	memcpy(curr->p_info->comm, fds, sizeof(int) * 2);
	pipe(fds);
	curr->p_info->stdout = ft_memalloc(sizeof(int) * 2);
	if (!(curr->right_child->right_child)) //Right child should *ALWAYS* be allocated
	{
		fds[0] = STDOUT_FILENO;
		fds[1] = STDOUT_FILENO;
	}
	memcpy(curr->p_info->stdout, fds, sizeof(int) * 2);
	curr->p_info->stderr = ft_memalloc(sizeof(int));
	if (curr->left_child && curr->right_child)
		build_leafs(curr);
}

void	build_default(t_ast *curr)
{
	t_process *info;

	if (!curr || *(curr->type) == operator)
		return ;
	if (!(info = ft_memalloc(sizeof(t_process))))
		return ;
	if (!(info->stdin = ft_memalloc(sizeof(int))))
	{
		free(info);
		return ;
	}
	*(info->stdin) = STDIN_FILENO;
	if (!(info->stdout = ft_memalloc(sizeof(int))))
	{
		free(info->stdin);
		free(info);
		return ;
	}
	*(info->stdout) = STDOUT_FILENO;
	if (!(info->stderr = ft_memalloc(sizeof(int))))
	{
		free(info->stdin);
		free(info->stdout);
		free(info);
		return ;
	}
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

int		build_info(t_ast *prev, t_ast *curr)
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
		run_operation(curr, 0);
	}
	build_info(curr, curr->right_child);
	return (0);
}

int		run_tree(t_ast *curr)
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
				return (op_handlers[i].exec(curr));
			i++;
		}
	}
	return (EXIT_FAILURE);
}

int		run_forest(t_ast **asts)
{
	int	i;

	i = 0;
	while (asts[i])
	{
		if (build_info(NULL, asts[i]))
			return (-1);
		if (run_tree(asts[i]))
			return (-1);
		return (255);
		i++;
	}
	return (0);
}
