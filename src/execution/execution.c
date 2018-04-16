/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:16:12 by asyed             #+#    #+#             */
/*   Updated: 2018/04/15 21:39:09 by asyed            ###   ########.fr       */
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

char **environ = NULL;

int		run_pipecmds(t_stack *cmd, t_pqueue *pids, t_environ *env)
{
	int		pid;
	t_ast	*process;

	if (!cmd || isempty_stack(cmd) || !(process = ft_stackpop(cmd)))
		return (EXIT_SUCCESS);
	if ((pid = fork()) == -1)
		return (EXIT_FAILURE);
	if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGCONT, SIG_DFL);
		signal(SIGTSTP, SIG_DFL);
		environ = env->environ;
		// ft_printf("-----> B (%d) [In: %d, Out: %d, Err: %d] |%s|\n", getpid(), *(process->p_info->stdin), *(process->p_info->stdout), *(process->p_info->stderr), *(process->token));
		if (handle_redirection(process))
		{
			// ft_printf("Failure????\n");
			exit(EXIT_FAILURE);
		}
		// ft_printf("\n-----> A (%d) [In: %d, Out: %d, Err: %d] |%s|\n", getpid(), *(process->p_info->stdin), *(process->p_info->stdout), *(process->p_info->stderr), *(process->token));
		// ft_printf("(%d) Closing %d %d\n", getpid(), process->p_info->stdin[1], process->p_info->stdout[1]);
		dup2(*(process->p_info->stdin), STDIN_FILENO);
		dup2(*(process->p_info->stdout), STDOUT_FILENO);
		dup2(*(process->p_info->stderr), STDERR_FILENO);
		execvP(*(process->token), getenv("PATH"), process->token);
		ft_printf("Error: %s: %s\n", strerror(errno), *(process->token));
		exit(EXIT_FAILURE);
	}
	if (*(process->p_info->stdin) != STDIN_FILENO)
		close(process->p_info->stdin[0]);
	if (*(process->p_info->stdout) != STDOUT_FILENO)
		close(process->p_info->stdout[0]);
	meta_free(process);
	ft_enpqueue(pids, &pid, sizeof(int), (int (*)(void *, void *))&compare);
	run_pipecmds(cmd, pids, env);
	return (EXIT_SUCCESS);
}

int		run_operation(t_ast *curr, uint8_t wait, t_environ *env)
{
	pid_t		pid;
	int			res;
	t_jobspec	job;

	if (!curr || *(curr->type) == OPERATOR)
		return (EXIT_FAILURE);
	if ((res = builtin_handler(curr, env)) != -1)
		return (res);
	if ((pid = fork()) == -1)
		return (EXIT_FAILURE);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGCONT, SIG_DFL);
		signal(SIGTSTP, SIG_DFL);
		// if (signal(SIGTSTP, &suspend) == SIG_ERR)
		// 	ft_printf("Error setting up signal handler: %s\n", strerror(errno));
		// else
		// 	ft_printf("Setup signal handler... %s\n", strerror(errno));
		// sleep(1);
		environ = env->environ;
		// ft_printf("-----> B [In: %d, Out: %d, Err: %d] |%s - %s|\n", *(curr->p_info->stdin), *(curr->p_info->stdout), *(curr->p_info->stderr), *(curr->token), curr->token[1]);
		if (handle_redirection(curr))
			exit(EXIT_FAILURE);
		// ft_printf(".......?\n");
		// ft_printf("-----> A [In: %d, Out: %d, Err: %d] |%s - %s|\n", *(curr->p_info->stdin), *(curr->p_info->stdout), *(curr->p_info->stderr), *(curr->token), curr->token[1]);
		dup2(*(curr->p_info->stdin), STDIN_FILENO);
		dup2(*(curr->p_info->stdout), STDOUT_FILENO);
		dup2(*(curr->p_info->stderr), STDERR_FILENO);
		execvP(*(curr->token), getenv("PATH"), curr->token);
		ft_printf("Error: %s: %s\n", strerror(errno), *(curr->token));
		exit(EXIT_FAILURE);
	}
	if (wait)
	{
		waitpid(pid, &res, WUNTRACED);
		if (WIFSTOPPED(res))
		{
			if (!(job.pids = new_stack()))
			{
				printf("Failed!?\n");
				return (EXIT_FAILURE);
			}
			if (ft_stackpush(job.pids, &pid, sizeof(pid_t)) == EXIT_FAILURE)
			{
				printf("wow failed to push to stack :c\n");
				return (EXIT_FAILURE);
			}
			job.name = strdup(*(curr->token));
			add_suspended(&job);
			ft_printf("Its suspended! (%d)\n", WSTOPSIG(res));
		}
		else
			ft_printf("Changed states!\n");
		return (res);
	}
	return (EXIT_SUCCESS);
}

/*
** Introduce error handling.
*/

void	pipe_carry(t_ast *prev, t_ast *curr)
{
	int fds[2];

	if (!curr || (!curr->p_info && !(curr->p_info = init_process())))
		return ;
	*(curr->p_info->stdin) = (prev ? *(curr->p_info->stdin) : STDIN_FILENO);
	curr->p_info->stdin[1] = (prev ? curr->p_info->stdin[1] : -1);
	pipe(fds);
	if (fcntl(fds[0], F_SETFD, FD_CLOEXEC) < 0 ||
		fcntl(fds[1], F_SETFD, FD_CLOEXEC) < 0)
		return ;
	memcpy(curr->p_info->comm, fds, sizeof(int) * 2);
	pipe(fds);
	if (fcntl(fds[0], F_SETFD, FD_CLOEXEC) < 0 ||
		fcntl(fds[1], F_SETFD, FD_CLOEXEC) < 0)
		return ;
	if (!(curr->right_child->right_child) ||
			(*(curr->right_child->type) == OPERATOR &&
			strcmp(*(curr->right_child->token), "|")))
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

/*
** Left will always be present, if not then its a failure.
*/

int		run_tree(t_ast *curr, __attribute__((unused))t_environ *env)
{
	int	i;

	if (!curr)
		return (EXIT_FAILURE);
	if (*(curr->type) == OPERATOR)
	{
		i = 0;
		while (op_handlers[i].check)
		{
			if (!op_handlers[i].check(*(curr->token)))
				return (op_handlers[i].exec(curr, env));
			i++;
		}
	}
	else
		return (run_operation(curr, 1, env));
	return (EXIT_FAILURE);
}

int		stringify(int fd, char **str)
{
	size_t	strlen;
	size_t	cap;
	int		res;

	strlen = 0;
	cap = 1024;
	if (!(*str = ft_memalloc(sizeof(char) * cap)))
		return (EXIT_FAILURE);
	while ((res = read(fd, &((*str)[strlen]), 1)) > 0)
	{
		if (strlen == (cap -1))
		{
			if (!(*str = meta_realloc(*str, sizeof(char) * (strlen * 2))))
				return (EXIT_FAILURE);
			cap = strlen * 2;
		}
		strlen++;
	}
	// printf("str = \"%s\"\n", *str);
	return (res);
}

int		subshell(t_queue *forest, char **substr, t_environ *env)
{
	pid_t	pid;
	int		fds[2];

	pipe(fds);
	if (fcntl(fds[0], F_SETFD, FD_CLOEXEC) < 0 ||
		fcntl(fds[1], F_SETFD, FD_CLOEXEC) < 0)
		return (EXIT_FAILURE);
	if ((pid = fork()) == -1)
		return (EXIT_FAILURE);
	if (!pid)
	{
		dup2(fds[1], STDOUT_FILENO);
		exit(run_forest(forest, NULL, env));
	}
	close(fds[1]);
	return (stringify(fds[0], substr));
}

int		run_forest(t_queue *forest, char **substr, t_environ *env)
{
	t_ast	*asts;

	if (!forest)
		return (EXIT_FAILURE);
	if (substr)
		return (subshell(forest, substr, env));
	while (!isempty_queue(forest) && (asts = ft_dequeue(forest)))
	{
		// ft_printf("Brown: %s\n", *(asts->token));
		if (build_info(NULL, (t_ast *)asts))
			return (EXIT_FAILURE);
		if (run_tree((t_ast *)asts, env) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}		
	return (EXIT_SUCCESS);
}
