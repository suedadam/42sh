/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:06:38 by asyed             #+#    #+#             */
/*   Updated: 2018/03/22 14:22:56 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*
** ToDo:
** - Handle empty pre-arg. (default to stdin/1).
*/

/*
** Create uni-directional FDs to keep uniform with pipes.
*/

int	redir_outfile(t_process *p_info, t_ast *ast, size_t pos)
{
	int	*fds;

	if (!(fds = malloc(sizeof(int) * 2)))
		return (EXIT_FAILURE);
	if ((fds[0] = open(ast->token[pos + 1], O_RDONLY)) == -1)
	{
		free(fds);
		return (EXIT_FAILURE);
	}
	if ((fds[1] = open(ast->token[pos + 1], O_WRONLY)) == -1)
	{
		free(fds);
		close(fds[0]);
		return (EXIT_FAILURE);
	}
	close(p_info->stdout[0]);
	close(p_info->stdout[1]);
	p_info->stdout = fds;
	return (EXIT_SUCCESS);
}

int	redir_infile(t_process *p_info, t_ast *ast, size_t pos)
{
	int	fd;

	if ((fd = open(ast->token[pos - 1], O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	p_info->stdin = fd;
	return (EXIT_SUCCESS);
}
