/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:16:12 by asyed             #+#    #+#             */
/*   Updated: 2018/04/13 21:48:04 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

struct s_ophandlers	op_handlers[] = {
	{&op_pipe_check, &op_pipe_exec},
	{&op_or_check, &op_or_exec},
	{&op_and_check, &op_and_exec},
	{NULL, NULL},
};

int			run_pipecmds(t_stack *cmd, t_queue *pids)
{
	int		pid;
	t_ast	*process;

	if (!cmd || isempty_stack(cmd))
		return (EXIT_SUCCESS);
	process = ft_stackpop(cmd); //Always okay?
	if ((pid = fork()) == -1)
	{
		printf("Failed to fork\n");
		abort();
	}
	if (!pid)
	{
		if (handle_redirection(process))
			exit(EXIT_FAILURE);
		printf("(%d) [In: %d, Out: %d, Err: %d] |%s|\n", getpid(), *(process->p_info->stdin), *(process->p_info->stdout), *(process->p_info->stderr), *(process->token));
		printf("(%d) Closing %d %d\n", getpid(), process->p_info->stdin[1], process->p_info->stdout[1]);
		dup2(*(process->p_info->stdin), STDIN_FILENO);
		dup2(*(process->p_info->stdout), STDOUT_FILENO);
		dup2(*(process->p_info->stderr), STDERR_FILENO);
		execvP(*(process->token), getenv("PATH"), process->token);
		exit(EXIT_FAILURE);
	}
	printf("Parent closed %d %d\n", process->p_info->stdin[0], process->p_info->stdout[0]);
	close(process->p_info->stdin[0]);
	if (*(process->p_info->stdout) != STDOUT_FILENO)
		close(process->p_info->stdout[0]);
	ft_enqueue(pids, &pid, sizeof(int));
	run_pipecmds(cmd, pids);
	return (EXIT_SUCCESS);
}

int		run_operation(t_ast *curr, uint8_t wait)
{
	pid_t	pid;
	int 	res;

	if (!curr || *(curr->type) == OPERATOR)
		return (EXIT_FAILURE);
	// if ((res = builtin_handler(curr)) != -1)
	// 	return (res);
	if ((pid = fork()) == -1)
		return (EXIT_FAILURE);
	if (pid == 0)
	{
		if (handle_redirection(curr))
			exit(EXIT_FAILURE);
		printf("[In: %d, Out: %d, Err: %d] |%s|\n", *(curr->p_info->stdin), *(curr->p_info->stdout), *(curr->p_info->stderr), *(curr->token));
		dup2(*(curr->p_info->stdin), STDIN_FILENO);
		dup2(*(curr->p_info->stdout), STDOUT_FILENO);
		dup2(*(curr->p_info->stderr), STDERR_FILENO);
		execvP(*(curr->token), getenv("PATH"), curr->token);
		exit(EXIT_FAILURE);
	}
	if (wait)
	{
		printf("Waiting\n");
		waitpid(pid, &res, 0);
		printf("Done waiting\n");
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
	else if (!(new->stdin = ft_memalloc(sizeof(int) * 2)))
	{
		free(new);
	}
	else if (!(new->stderr = ft_memalloc(sizeof(int) * 2)))
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
	else
		return (new);
	return (NULL);
}

void	build_leafs(t_ast *curr)
{
	t_process *info;

	if (!curr || !curr->left_child || !(info = init_process()))
	{
		printf("++++++++++ failed? %p %p %p\n", curr, curr->left_child, info);
		return ;
	}
	*(info->stdin) = *(curr->p_info->stdin);
	info->stdin[1] = curr->p_info->stdin[1];
	*(info->stdout) = curr->p_info->comm[1];
	info->stdout[1] = curr->p_info->comm[0];
	*(info->stderr) = *(curr->p_info->stderr);
	info->stderr[1] = curr->p_info->stderr[1];
	curr->left_child->p_info = info;
	if (!curr->right_child || !(info = init_process()))
		return ;
	*(info->stdin) = curr->p_info->comm[0];
	info->stdin[1] = curr->p_info->comm[1];
	*(info->stdout) = curr->p_info->stdout[1];
	info->stdout[1] = curr->p_info->stdout[0];
	*(info->stderr) = *(curr->p_info->stderr);
	info->stderr[1] = curr->p_info->stderr[1];
	curr->right_child->p_info = info;
}

void	build_carry(t_ast *curr)
{
	t_process	*info;

	if (!curr || !(info = init_process()))
		return ;
	memcpy(info, curr, sizeof(t_process));
	// *(info->stdin) = *(curr->p_info->stdin);
	// info->stdin[1] = curr->p_info->stdin[1];
	// *(info->stdout) = *(curr->p_info->stdout);
	// info->stdout[1] = curr->p_info->stdout[1];
	// *(info->stderr) = *(curr->p_info->stderr);
	// info->stderr[1] = curr->p_info->stderr[1];
	curr->left_child->p_info = info;
}

/*
** -> 1. This is only set when a pipe created it and the operator isn't a pipe.
**			This in turn needs to carry it over to the left leaf and reverse execute and wait
*/

void	build_operator(t_ast *prev, t_ast *curr)
{
	if (!curr)
		return ;
	if (curr->p_info) // (->1)
	{
		build_carry(curr);
		build_default(curr->right_child);
		return ;
	}
	build_default(curr->left_child);
	build_default(curr->right_child);
}

/*
** Introduce error handling.
*/

void	pipe_carry(t_ast *prev, t_ast *curr)
{
	int fds[2];

	if (!curr)
		return ;
	if (!curr->p_info && !(curr->p_info = init_process()))
		return ;
	*(curr->p_info->stdin) = (prev ? *(curr->p_info->stdin) : STDIN_FILENO);
	curr->p_info->stdin[1] = (prev ? curr->p_info->stdin[1] : -1);
	pipe(fds);
	if (fcntl(fds[0], F_SETFD, FD_CLOEXEC) < 0 || fcntl(fds[1], F_SETFD, FD_CLOEXEC) < 0)
		return ;
	memcpy(curr->p_info->comm, fds, sizeof(int) * 2);
	pipe(fds);
	if (fcntl(fds[0], F_SETFD, FD_CLOEXEC) < 0 || fcntl(fds[1], F_SETFD, FD_CLOEXEC) < 0)
		return ;
	if (!(curr->right_child->right_child) ||
		 (*(curr->right_child->type) == OPERATOR && strcmp(*(curr->right_child->token), "|")))
	{
		fds[0] = STDOUT_FILENO;
		fds[1] = STDOUT_FILENO;
	}
	memcpy(curr->p_info->stdout, fds, sizeof(int) * 2);
	*(curr->p_info->stderr) = STDERR_FILENO;
	if (curr->left_child && curr->right_child)
	{
		build_leafs(curr);
		build_info(curr, curr->right_child);
	}
}

void	build_default(t_ast *curr)
{
	t_process *info;

	if (!curr || *(curr->type) == OPERATOR)
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

int		build_info(t_ast *prev, t_ast *curr)
{
	if (!curr)
		return (EXIT_FAILURE);
	if (*(curr->type) == OPERATOR)
	{
		if (!strcmp(*(curr->token), "|"))
			pipe_carry(prev, curr);
		else
			build_operator(prev, curr);
	}
	else if (!prev)
	{
		build_default(curr);
		run_operation(curr, 0);
	}
	else
		build_info(curr, curr->right_child);
	return (EXIT_SUCCESS);
}

/*
** Left will always be present, if not then its a failure.
*/

int		run_tree(t_ast *curr)
{
	int	i;

	if (!curr || !curr->left_child)
		return (EXIT_FAILURE);
	if (*(curr->type) == OPERATOR)
	{
		i = 0;
		while (op_handlers[i].check)
		{
			if (!op_handlers[i].check(*(curr->token)))
			{
				printf("Running op |%d|\n", i);
				return (op_handlers[i].exec(curr));
			}
			i++;
		}
	}
	else
		return (run_operation(curr, 0));
	return (EXIT_FAILURE);
}

int		run_forest(t_queue *forest)
{
	t_ast	*asts;

	if (!forest)
		return (EXIT_FAILURE);
	while (!isempty_queue(forest) && (asts = ft_dequeue(forest)))
	{
		if (build_info(NULL, (t_ast *)asts))
			return (EXIT_FAILURE);
		if (run_tree((t_ast *)asts))
			return (EXIT_FAILURE);		
	}
	return (EXIT_SUCCESS);
}
