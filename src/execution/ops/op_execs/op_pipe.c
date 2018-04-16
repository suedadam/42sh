/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:27:28 by asyed             #+#    #+#             */
/*   Updated: 2018/04/15 21:38:20 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <signal.h>

void	itterate_pipes(t_stack *cmdstack, t_ast *curr)
{
	if (*(curr->type) == OPERATOR && !strcmp(*(curr->token), "|"))
	{
		ft_stackpush(cmdstack, curr->left_child, sizeof(t_ast));
		meta_free(curr->left_child);
		itterate_pipes(cmdstack, curr->right_child);
		if (!curr->right_child || *(curr->right_child->type) != OPERATOR)
		{
			ft_stackpush(cmdstack, curr->right_child, sizeof(t_ast));
			meta_free(curr->right_child);
			t_ast *peak;
			peak = ft_stackpeak(cmdstack);
			return ;
		}
	}
}

int		suspend_chain(t_pqueue *pids, __attribute__((unused)) pid_t deadpid, char *name)
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
	job.name = strdup(name);
	add_suspended(&job);
	return (EXIT_SUCCESS);
}

int		op_pipe_exec(t_ast *curr, t_environ *env)
{
	t_pqueue	pids;
	t_stack		cmdstack;
	pid_t		res;
	pid_t		*kpid;

	if (!curr)
		return (EXIT_FAILURE);
	cmdstack.top = NULL;
	pids.first = NULL;
	itterate_pipes(&cmdstack, curr);
	run_pipecmds(&cmdstack, &pids, env);
	if (!(kpid = ft_memalloc(sizeof(int))))
		return (EXIT_FAILURE);
	while (pids.first && (res = wait3(kpid, WUNTRACED, NULL)) >= 0)
	{
		if (WEXITSTATUS(*kpid) || WIFSTOPPED(*kpid))
		{
			if (WIFSTOPPED(*kpid))
			{
				ft_printf("Received suspend calls!!!\n");
				// return (suspend_chain(&pids, res, *(curr->token)));
				suspend_chain(&pids, res, *(curr->token));
				print_first();
				return (EXIT_SUCCESS);
			}
			// kill_chain(&pids, res);
			meta_free(kpid);
			while (pids.first)
			{
				if (!(kpid = ft_depqueue(&pids)))
					return (EXIT_FAILURE);
				kill(*kpid, SIGKILL);
				meta_free(kpid);
			}
		}
		printf("%d", WEXITSTATUS(*kpid));
	}
	return (EXIT_SUCCESS);
}
