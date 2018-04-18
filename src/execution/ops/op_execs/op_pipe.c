/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:27:28 by asyed             #+#    #+#             */
/*   Updated: 2018/04/16 08:42:35 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <signal.h>

void	itterate_pipes(t_stack *cmdstack, t_ast *curr)
{
	if (*(curr->type) == OPERATOR && !strcmp(*(curr->token), "|"))
	{
		ft_stackpush(cmdstack, curr->left_child, sizeof(t_ast));
		itterate_pipes(cmdstack, curr->right_child);
		if (!curr->right_child || *(curr->right_child->type) != OPERATOR)
		{
			ft_stackpush(cmdstack, curr->right_child, sizeof(t_ast));
			return ;
		}
	}
}

int		suspend_chain(t_pqueue *pids, char *name)
{
	t_jobspec	job;
	pid_t		*pid;

	if (!(job.pids = new_stack()))
		return (EXIT_FAILURE);
	while (pids->first)
	{
		if (!(pid = ft_depqueue(pids)))
			return (EXIT_FAILURE);
		if (ft_stackpush(job.pids, pid, sizeof(pid_t)))
			return (EXIT_FAILURE);
		kill(*pid, SIGTSTP);
		meta_free(pid);
	}
	job.name = ft_strdup(name);
	add_suspended(&job);
	return (EXIT_SUCCESS);
}

int		itterate_queue(t_pqueue *pids, int signal, pid_t deadpid)
{
	pid_t	*kpid;

	while (pids->first && *(int *)pids->first->content <= deadpid)
	{
		if (!(kpid = ft_depqueue(pids)))
			return (EXIT_FAILURE);
		if (signal)
			kill(*kpid, signal);
		meta_free(kpid);
	}
	return (EXIT_SUCCESS);
}

int		op_pipe_exec(t_ast *curr, t_environ *env)
{
	t_pqueue	pids;
	t_stack		cmdstack;
	pid_t		res;
	pid_t		kpid;

	if (!curr)
		return (EXIT_FAILURE);
	cmdstack.top = NULL;
	pids.first = NULL;
	itterate_pipes(&cmdstack, curr);
	run_pipecmds(&cmdstack, &pids, env);
	while (pids.first && (res = wait3(&kpid, WUNTRACED, NULL)) >= 0)
	{
		if (WEXITSTATUS(kpid) || WIFSTOPPED(kpid))
		{
			if (res)
				return (suspend_chain(&pids, *(curr->token)));
			if (itterate_queue(&pids, SIGKILL, res) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		if (itterate_queue(&pids, 0, res) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
