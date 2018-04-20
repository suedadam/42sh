/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:27:28 by asyed             #+#    #+#             */
/*   Updated: 2018/04/20 00:54:04 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <signal.h>

int		op_hijack(t_ast *curr, t_environ *env, t_pqueue *pids, t_stack *cmds)
{
	int	i;
	int	res;

	res = EXIT_SUCCESS;
	if (!curr)
		return (EXIT_FAILURE);
	if (*(curr->type) == OPERATOR)
	{
		i = 0;
		while (ophijack_handlers[i].check)
		{
			if (!ophijack_handlers[i].check(*(curr->token)))
				return (ophijack_handlers[i].exec(curr, env, pids, cmds));
			i++;
		}
	}
	return (EXIT_FAILURE);
}

int		itterate_pipes(t_stack *cmdstack, t_ast *curr,
		t_environ *env, t_pqueue *pids)
{
	if (*(curr->type) == OPERATOR && !strcmp(*(curr->token), "|"))
	{
		ft_stackpush(cmdstack, curr->left_child, sizeof(t_ast));
		itterate_pipes(cmdstack, curr->right_child, env, pids);
		if (curr->right_child)
		{
			if (*(curr->right_child->type) == OPERATOR &&
				strcmp(*(curr->right_child->token), "|"))
			{
				ft_stackpush(cmdstack, curr->right_child->left_child,
						sizeof(t_ast));
				return (op_hijack(curr->right_child, env, pids, cmdstack));
			}
			else if (*(curr->right_child->type) != OPERATOR)
				ft_stackpush(cmdstack, curr->right_child, sizeof(t_ast));
			return (-1);
		}
	}
	return (-1);
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

	while (pids->first)
	{
		if (!(kpid = peek_pqueue(pids)))
			return (EXIT_FAILURE);
		if (*kpid >= deadpid)
			return (EXIT_SUCCESS);
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
	if ((res = itterate_pipes(&cmdstack, curr, env, &pids)) != -1)
		return (res);
	run_pipecmds(&cmdstack, &pids, env);
	while (pids.first && (res = wait3(&kpid, WUNTRACED, NULL)) >= 0)
	{
		if (WIFSTOPPED(kpid))
			return (suspend_chain(&pids, *(curr->token)));
		if (itterate_queue(&pids, SIGKILL, res) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
