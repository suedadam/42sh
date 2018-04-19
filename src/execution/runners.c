/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runners.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 03:14:11 by asyed             #+#    #+#             */
/*   Updated: 2018/04/19 01:48:41 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*
** Left will always be present, if not then its a failure.
*/

int		run_tree(t_ast *curr, t_environ *env)
{
	int	i;
	int	res;

	res = EXIT_SUCCESS;
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
		if (strlen == (cap - 1))
		{
			if (!(*str = meta_realloc(*str, sizeof(char) * (strlen * 2))))
				return (EXIT_FAILURE);
			cap = strlen * 2;
		}
		strlen++;
	}
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
		return (EXIT_SUCCESS);
	if (substr)
		return (subshell(forest, substr, env));
	while (!isempty_queue(forest) && (asts = ft_dequeue(forest)))
	{
		if (build_info(NULL, (t_ast *)asts))
		{
			errno = 8;
			return (EXIT_FAILURE);
		}
		if (run_tree((t_ast *)asts, env) == EXIT_FAILURE)
		{
			errno = 8;
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
