/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 22:34:50 by asyed             #+#    #+#             */
/*   Updated: 2018/04/19 00:48:59 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		compare(int *n1, int *n2)
{
	if (*n1 < *n2)
		return (0);
	return (1);
}

void	help_free(t_process *new)
{
	meta_free(new);
	meta_free(new->stdin);
}

void	free_process(t_process *process)
{
	meta_free(process->stdin);
	if (process->stderr != process->stdin && process->stderr != process->stdout)
		meta_free(process->stderr);
	if (process->stdout != process->stdin && process->stdout != process->stderr)
		meta_free(process->stdout);
	meta_free(process->comm);
	process->comm = NULL;
	meta_free(process);
}

void	*init_process(void)
{
	t_process	*new;

	if (!(new = ft_memalloc(sizeof(t_process))))
		return (NULL);
	else if (!(new->stdin = ft_memalloc(sizeof(int) * 2)))
		meta_free(new);
	else if (!(new->stderr = ft_memalloc(sizeof(int) * 2)))
		help_free(new);
	else if (!(new->stdout = ft_memalloc(sizeof(int) * 2)))
	{
		help_free(new);
		meta_free(new->stderr);
	}
	else if (!(new->comm = ft_memalloc(sizeof(int) * 2)))
	{
		meta_free(new);
		meta_free(new->stdin);
		meta_free(new->stderr);
		meta_free(new->stdout);
	}
	return (new);
}

int		fd_redir(t_ast *curr, int **src, int pos, uint8_t closer)
{
	int	dtmp;
	int fds[2];

	if (!curr->token[pos + 2] || (!(dtmp = ft_atoi(curr->token[pos + 2]))
								&& strcmp(curr->token[pos + 2], "-")))
		return (EXIT_SUCCESS);
	if (dtmp == 1)
		*src = curr->p_info->stdout;
	else if (dtmp == 2)
		*src = curr->p_info->stderr;
	else if (closer && *(curr->token[pos + 2]) == '-')
	{
		pipe_ops(fds);
		close(**src);
		**src = fds[1];
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
