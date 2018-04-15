/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suspend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:52:30 by asyed             #+#    #+#             */
/*   Updated: 2018/04/14 21:15:45 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

typedef struct	s_jobspec
{
	pid_t	pid;
	char	*name;
}				t_jobspec;

t_queue	*g_jobs = NULL;

/*
** Strdup to get out of the way of freeing everything at the end.
** This segment will stay with the job control throughout the duration of the 
** program's life.
*/

void	add_suspended(pid_t pid, char *name)
{
	t_jobspec job;

	if (!g_jobs)
		g_jobs = new_queue();
	job.pid = pid;
	job.name = strdup(name);
	if ((ft_enqueue(g_jobs, &job, sizeof(t_jobspec))) == EXIT_FAILURE)
	{
		printf("Failed to add.\n");
		return ;
	}
	printf("Top of queue = \"%s\" (%p) |%d|\n", ((t_jobspec *)peek_queue(g_jobs))->name, ((t_jobspec *)peek_queue(g_jobs))->name, ((t_jobspec *)peek_queue(g_jobs))->pid);
}

void	unsuspend(char *name)
{
	t_node		*list;
	t_jobspec	*job;

	if (isempty_queue(g_jobs) || !name)
		return ;
	list = g_jobs->first;
	while (list)
	{
		printf("Itterating through\n");
		if (!(job = list->content))
		{
			ft_printf("What the balls?\n");
			return ;
		}
		if (!strcmp(job->name, name))
		{
			printf("Found it! %s\n", name);
			kill(job->pid, SIGCONT);
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
			return ;
		}
		list = list->next;
	}
}

void	print_first(void)
{
	if (isempty_queue(g_jobs))
		printf("Empty!!!\n");
	else
		printf("Top of queue = \"%s\" (%p) |%d|\n", ((t_jobspec *)peek_queue(g_jobs))->name, ((t_jobspec *)peek_queue(g_jobs))->name, ((t_jobspec *)peek_queue(g_jobs))->pid);
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
