/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:27:28 by asyed             #+#    #+#             */
/*   Updated: 2018/04/13 23:25:30 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <signal.h>

void	itterate_pipes(t_stack *cmdstack, t_ast *curr)
{
	if (*(curr->type) == OPERATOR && !strcmp(*(curr->token), "|"))
	{
		ft_stackpush(cmdstack, curr->left_child, sizeof(t_ast));
		free(curr->left_child);
		itterate_pipes(cmdstack, curr->right_child);
		if (!curr->right_child || *(curr->right_child->type) != OPERATOR)
		{
			ft_stackpush(cmdstack, curr->right_child, sizeof(t_ast));
			free(curr->right_child);
			t_ast *peak;
			peak = ft_stackpeak(cmdstack);
			return ;
		}
	}
}

int		op_pipe_exec(t_ast *curr)
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
	run_pipecmds(&cmdstack, &pids);
	if (!(kpid = malloc(sizeof(int))))
		return (EXIT_FAILURE);
	while ((res = wait(kpid)) >= 0)
	{
		if (WEXITSTATUS(*kpid))
		{
			free(kpid);
			while (pids.first)
			{
				if (!(kpid = ft_depqueue(&pids)))
					return (EXIT_FAILURE);
				kill(*kpid, SIGKILL);
				free(kpid);
			}
		}
	}
	return (EXIT_SUCCESS);
}
