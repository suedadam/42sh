/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suspend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:52:30 by asyed             #+#    #+#             */
/*   Updated: 2018/04/15 21:38:39 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_queue	*g_jobs = NULL;

/*
** Strdup to get out of the way of freeing everything at the end.
** This segment will stay with the job control throughout the duration of the 
** program's life.
*/

void	add_suspended(t_jobspec *job)
{
	if (!g_jobs)
		g_jobs = new_queue();
	if ((ft_enqueue(g_jobs, job, sizeof(t_jobspec))) == EXIT_FAILURE)
	{
		printf("Failed to add.\n");
		return ;
	}
	printf("Top of queue = \"%s\" (%p)\n", ((t_jobspec *)peek_queue(g_jobs))->name, ((t_jobspec *)peek_queue(g_jobs))->name);
}

pid_t	unsuspend_chain(t_stack *jobs)
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

pid_t	unsuspend(char *name)
{
	t_node		*list;
	t_jobspec	*job;
	pid_t		ret;

	if (isempty_queue(g_jobs))
	{
		ft_printf("Empty queue!\n");
		return (-2);
	}
	list = g_jobs->first;
	if (!name)
	{
		printf("Nothing! dequeueing!\n");
		job = ft_dequeue(g_jobs);
		return (unsuspend_chain(job->pids));
	}
	while (list)
	{
		printf("Itterating through\n");
		if (!(job = list->content))
		{
			ft_printf("What the balls?\n");
			return (-1);
		}
		if (!strcmp(job->name, name))
		{
			ret = unsuspend_chain(job->pids);
			printf("Found it! %s\n", name);
			// kill(job->pid, SIGCONT);
			if (peek_queue(g_jobs) == job)
				ft_dequeue(g_jobs);
			else
			{
				if (list->previous)
					list->previous = list->next;
				if (list->next)
					list->next->previous = list->previous;
				meta_free(job);
				meta_free(list);				
			}
			return (ret);
		}
		list = list->next;
	}
	return (-2);
}

void	print_jobs(void)
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
	// if (isempty_queue(g_jobs))
	// 	printf("Empty!!!\n");
	// else
	// 	printf("Top of queue = \"%s\" (%p)\n", ((t_jobspec *)peek_queue(g_jobs))->name, ((t_jobspec *)peek_queue(g_jobs))->name);
}

// int	g_lol;

// void	suspend(int c)
// {
// 	ft_printf("Suspending task. got %d\n", c);
// 	g_lol = c;
// 	// pause();
// 	// ft_printf("Unsuspended\n");
// }

// void	unsuspend(int c)
// {
// 	ft_printf("Suspending task. got %d\n", c);
// 	pause();
// 	ft_printf("Unsuspended\n");
// }
