/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:06:38 by asyed             #+#    #+#             */
/*   Updated: 2018/04/19 23:25:30 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <errno.h>

struct s_redir_op	redir_ops[] = {
	{"<", &ops_read_from},
	{">", &ops_redir_to},
	{">>", &ops_append_to},
	{NULL, NULL},
};

int		ops_read_from(t_ast *curr, int pos)
{
	int	**src;

	if (curr->token[pos - 1] &&
		(ft_atoi(curr->token[pos - 1]) || *(curr->token[pos - 1]) == '0'))
	{
		meta_free(curr->token[pos - 1]);
		curr->token[pos - 1] = NULL;
	}
	if (!curr->token[pos + 1])
		return (EXIT_FAILURE);
	src = &(curr->p_info->stdin);
	if ((**src = open(curr->token[pos + 1],
		O_APPEND | O_CREAT | O_RDWR | O_CLOEXEC, S_IRUSR | S_IWUSR)) == -1)
		return (EXIT_FAILURE);
	return (free_after(curr, pos));
}

int		ops_append_to(t_ast *curr, int pos)
{
	int		**src;

	if (!(src = valid_input(curr->token[pos - 1], -1, curr)))
		src = &(curr->p_info->stdout);
	else
	{
		meta_free(curr->token[pos - 1]);
		curr->token[pos - 1] = NULL;
	}
	if (!curr->token[pos + 1])
		return (EXIT_FAILURE);
	if (*(curr->token[pos + 1]) == '&')
	{
		if (fd_redir(curr, src, pos, 0) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if ((**src = open(curr->token[pos + 1],
		O_APPEND | O_CREAT | O_RDWR | O_CLOEXEC, S_IRUSR | S_IWUSR)) == -1)
		return (EXIT_FAILURE);
	return (free_after(curr, pos));
}

/*
** Free everything after curr->token[pos - 1] (NULL terminated array) ^^^^
*/

int		ops_redir_to(t_ast *curr, int pos)
{
	int		**src;

	if (!(src = valid_input(curr->token[pos - 1], -1, curr)))
		src = &(curr->p_info->stdout);
	else
	{
		meta_free(curr->token[pos - 1]);
		curr->token[pos - 1] = NULL;
	}
	if (!curr->token[pos + 1])
		return (EXIT_FAILURE);
	if (*(curr->token[pos + 1]) == '&')
	{
		if (fd_redir(curr, src, pos, 1) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (curr->token[pos + 1] && (**src = open(curr->token[pos + 1],
		O_TRUNC | O_CREAT | O_RDWR | O_CLOEXEC, S_IRUSR | S_IWUSR)) == -1)
		return (EXIT_FAILURE);
	return (free_after(curr, pos));
}

int		handle_redirection(t_ast *curr)
{
	int	i;
	int	j;

	if (!curr)
		return (EXIT_FAILURE);
	i = 0;
	if (curr->type[i] != WORD)
		return (EXIT_SUCCESS);
	while (curr->token[i])
	{
		j = 0;
		while (redir_ops[j].opflag)
		{
			if (!ft_strcmp(curr->token[i], redir_ops[j].opflag))
			{
				if (!curr || redir_ops[j].func(curr, i))
					return (EXIT_FAILURE);
				break ;
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
