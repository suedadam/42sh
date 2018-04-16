/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:05:58 by asyed             #+#    #+#             */
/*   Updated: 2018/04/15 21:52:56 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	builtin_fg(char *argv[], __attribute__((unused)) t_environ *env)
{
	pid_t		ret;
	pid_t		res;
	t_jobspec	job;

	if (!argv || !argv[0])
		return (EXIT_FAILURE);
	if ((ret = unsuspend(argv[1])) >= 0)
	{
		waitpid(ret, &res, WUNTRACED);
		if (WIFSTOPPED(res))
		{
			if (!(job.pids = new_stack()))
			{
				// printf("Failed!?\n");
				return (EXIT_FAILURE);
			}
			if (ft_stackpush(job.pids, &ret, sizeof(pid_t)) == EXIT_FAILURE)
			{
				// printf("wow failed to push to stack :c\n");
				return (EXIT_FAILURE);
			}
			job.name = strdup("Hello World!");
			add_suspended(&job);
			ft_printf("Its suspended! (%d)\n", WSTOPSIG(res));
		}
		// else
			// ft_printf("Changed states!\n");
		return (res);
	}
	return ((ret == -1) ? EXIT_FAILURE : EXIT_SUCCESS);
}

int	builtin_bg(char *argv[], __attribute__((unused)) t_environ *env)
{
	pid_t		ret;

	if (!argv || !argv[0])
		return (EXIT_FAILURE);
	ret = unsuspend(argv[1]);
	return ((ret == -1) ? EXIT_FAILURE : EXIT_SUCCESS);
}

int	builtin_jobs(char *argv[], __attribute__((unused)) t_environ *env)
{

	if (!argv)
		return (EXIT_FAILURE);
	print_jobs();
	return (EXIT_SUCCESS);
}
