/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hijack_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 01:02:39 by asyed             #+#    #+#             */
/*   Updated: 2018/04/19 02:00:58 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		op_and_exec_hijacked(t_ast *curr, t_environ *env, t_pqueue *pids, t_stack *cmds)
{
	pid_t	res;
	pid_t	kpid;
	uint8_t	status;

	if (!curr)
		return (EXIT_FAILURE);
	run_pipecmds(cmds, pids, env);
	status = 1;
	while (pids->first && (res = wait3(&kpid, WUNTRACED, NULL)) >= 0)
	{
		status = WEXITSTATUS(kpid);
		if (WIFSTOPPED(kpid))
			return (suspend_chain(pids, *(curr->token)));
		if (itterate_queue(pids, SIGKILL, res) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (!status)
		return (run_tree(curr->right_child, env));
	return (EXIT_SUCCESS);
}

int		op_or_exec_hijacked(t_ast *curr, t_environ *env, t_pqueue *pids, t_stack *cmds)
{
	pid_t	res;
	pid_t	kpid;
	uint8_t	status;

	if (!curr)
		return (EXIT_FAILURE);
	run_pipecmds(cmds, pids, env);
	status = 0;
	while (pids->first && (res = wait3(&kpid, WUNTRACED, NULL)) >= 0)
	{
		status = WEXITSTATUS(kpid);
		if (WIFSTOPPED(kpid))
			return (suspend_chain(pids, *(curr->token)));
		if (itterate_queue(pids, SIGKILL, res) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (status)
		return (run_tree(curr->right_child, env));
	return (EXIT_SUCCESS);
}
