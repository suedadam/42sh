/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:06:38 by asyed             #+#    #+#             */
/*   Updated: 2018/04/14 21:04:32 by asyed            ###   ########.fr       */
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
	if ((**src = open(curr->token[pos + 1], O_APPEND | O_CREAT | O_RDWR | O_CLOEXEC, S_IRUSR | S_IWUSR)) == -1)
		return (EXIT_FAILURE);
	meta_free(curr->token[pos + 1]);
	meta_free(curr->token[pos]);
	curr->token[pos] = NULL;
	return (EXIT_SUCCESS);
}

int		ops_append_to(t_ast *curr, int pos)
{
	int		stmp;
	int		dtmp;
	int		**src;

	if (!(stmp = ft_atoi(curr->token[pos - 1])) || stmp == 1)
		src = &(curr->p_info->stdout);
	else if (stmp == 2)
		src = &(curr->p_info->stderr);
	else
		return (EXIT_FAILURE);
	if ((stmp && stmp != 1) || (stmp == 1 && curr->token[pos - 1][0] == '1'))
	{
		meta_free(curr->token[pos - 1]);
		curr->token[pos - 1] = NULL;
	}
	if (*(curr->token[pos + 1]) == '&')
	{
		dtmp = ft_atoi(&(curr->token[pos + 1][1]));
		if (dtmp == 1)
			*src = curr->p_info->stdout;
		else if (dtmp == 2)
			*src = curr->p_info->stderr;
		else
			return (EXIT_FAILURE);
	}
	else if ((**src = open(curr->token[pos + 1], O_APPEND | O_CREAT | O_RDWR | O_CLOEXEC, S_IRUSR | S_IWUSR)) == -1)
		return (EXIT_FAILURE);
	meta_free(curr->token[pos]);
	curr->token[pos] = NULL;
	meta_free(curr->token[pos + 1]);
	curr->token[pos + 1] = NULL;
	return (EXIT_SUCCESS);
}

/*
** Free everything after curr->token[pos - 1] (NULL terminated array) ^^^^
*/

int		ops_redir_to(t_ast *curr, int pos)
{
	int		stmp;
	int		dtmp;
	int		**src;

	if (!(stmp = ft_atoi(curr->token[pos - 1])) || stmp == 1)
		src = &(curr->p_info->stdout);
	else if (stmp == 2)
		src = &(curr->p_info->stderr);
	else
		return (EXIT_FAILURE);
	if ((stmp && stmp != 1) || (stmp == 1 && curr->token[pos - 1][0] == '1'))
	{
		meta_free(curr->token[pos - 1]);
		curr->token[pos - 1] = NULL;
	}
	if (*(curr->token[pos + 1]) == '&')
	{
		dtmp = ft_atoi(&(curr->token[pos + 1][1]));
		if (dtmp == 1)
			*src = curr->p_info->stdout;
		else if (dtmp == 2)
			*src = curr->p_info->stderr;
		else if (curr->token[pos + 1][1] == '-')
			**src = -1;
		else
			return (EXIT_FAILURE);
	}
	else if ((**src = open(curr->token[pos + 1], O_APPEND | O_CREAT | O_RDWR | O_CLOEXEC, S_IRUSR | S_IWUSR)) == -1)
		return (EXIT_FAILURE);
	meta_free(curr->token[pos]);
	curr->token[pos] = NULL;
	meta_free(curr->token[pos + 1]);
	curr->token[pos + 1] = NULL;
	return (EXIT_SUCCESS);
}

int		handle_redirection(t_ast *curr)
{
	int	i;
	int	j;

	if (!curr)
		return (EXIT_FAILURE);
	i = 0;
	while (curr->token[i])
	{
		j = 0;
		while (redir_ops[j].opflag)
		{
			if (!strcmp(curr->token[i], redir_ops[j].opflag))
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
