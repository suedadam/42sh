/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suspend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:52:30 by asyed             #+#    #+#             */
/*   Updated: 2018/04/16 03:09:49 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_queue	*g_jobs = NULL;

/*
** Strdup to get out of the way of freeing everything at the end.
** This segment will stay with the job control throughout the duration of the
** program's life.
*/

void			add_suspended(t_jobspec *job)
{
	if (!g_jobs)
		g_jobs = new_queue();
	if ((ft_enqueue(g_jobs, job, sizeof(t_jobspec))) == EXIT_FAILURE)
		return ;
}

pid_t			unsuspend_chain(t_stack *jobs)
{
	pid_t	*pid;
	pid_t	ret;

	ret = 0;
	while (jobs->top)
	{
		if (!(pid = ft_stackpop(jobs)))
			return (-1);
		if (!ret)
			ret = *pid;
		kill(*pid, SIGCONT);
		meta_free(pid);
	}
	return (ret);
}

static void		linkfree(t_node *list, t_jobspec *job)
{
	if (list->previous)
		list->previous = list->next;
	if (list->next)
		list->next->previous = list->previous;
	meta_free(job->name);
	meta_free(job);
	meta_free(list);
}

pid_t			unsuspend(char *name)
{
	t_node		*list;
	t_jobspec	*job;
	pid_t		ret;

	if (isempty_queue(g_jobs) || !(list = g_jobs->first))
		return (-2);
	if (!name)
	{
		job = ft_dequeue(g_jobs);
		return (unsuspend_chain(job->pids));
	}
	while (list)
	{
		if ((job = list->content) && !strcmp(job->name, name))
		{
			ret = unsuspend_chain(job->pids);
			if (peek_queue(g_jobs) == job)
				ft_dequeue(g_jobs);
			else
				linkfree(list, job);
			return (ret);
		}
		list = list->next;
	}
	return (-2);
}

void			print_jobs(void)
{
	int			i;
	t_node		*node;
	t_jobspec	*job;

	if (!g_jobs || !(node = g_jobs->first))
		return ;
	i = 0;
	while (node)
	{
		if (!(job = node->content) || !job->name)
			return ;
		ft_printf("[%d] + Name: %s\n", job->name);
		node = node->next;
	}
}
