/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 08:32:17 by asyed             #+#    #+#             */
/*   Updated: 2018/04/16 08:34:49 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "ft_proto.h"

int		pipe_ops(int *fds)
{
	pipe(fds);
	if (fcntl(fds[0], F_SETFD, FD_CLOEXEC) < 0 ||
		fcntl(fds[1], F_SETFD, FD_CLOEXEC) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	exec_init(t_ast *process)
{
	signaldef_handlers();
	if (handle_redirection(process))
		exit(EXIT_FAILURE);
	dup2(*(process->p_info->stdin), STDIN_FILENO);
	dup2(*(process->p_info->stdout), STDOUT_FILENO);
	dup2(*(process->p_info->stderr), STDERR_FILENO);
}

void	parent_pipes(t_ast *curr)
{
	if (*(curr->p_info->stdin) != STDIN_FILENO)
		close(*(curr->p_info->stdin));
	if (*(curr->p_info->stdout) != STDOUT_FILENO)
		close(*(curr->p_info->stdin));
	meta_free(curr);
}
