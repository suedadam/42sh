/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:06:38 by asyed             #+#    #+#             */
/*   Updated: 2018/03/29 22:01:47 by asyed            ###   ########.fr       */
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
	int	ftmp;
	int	**src;

	if (!(ftmp = ft_atoi(curr->token[pos - 1]) && curr->token[pos - 1][0] != '0') || ftmp == 0)
		src = &(curr->p_info->stdin);
	else
		return (EXIT_FAILURE);
	if ((**src = open(curr->token[pos + 1], O_APPEND | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR)) == -1)
		return (EXIT_FAILURE);
	curr->token[(ftmp || curr->token[pos - 1][0] == '0') ? pos - 1 : pos] = NULL;
	return (EXIT_SUCCESS);
}

int		ops_append_to(t_ast *curr, int pos)
{
	int		ftmp;
	int		dtmp;
	int		**src;

	if (!(ftmp = ft_atoi(curr->token[pos - 1])) || ftmp == 1)
		src = &(curr->p_info->stdout);
	else if (ftmp == 2)
		src = &(curr->p_info->stderr);
	else
		return (EXIT_FAILURE);
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
	else if ((**src = open(curr->token[pos + 1], O_APPEND | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR)) == -1)
		return (EXIT_FAILURE);
	// free(curr->token[pos - 1]); //Eable when using Satkins'
	curr->token[(ftmp) ? pos - 1 : pos] = NULL;
	return (EXIT_SUCCESS);
}

/*
** Free everything after curr->token[pos - 1] (NULL terminated array) ^^^^
*/

int		ops_redir_to(t_ast *curr, int pos)
{
	int		ftmp;
	int		dtmp;
	int		**src;

	if (!(ftmp = ft_atoi(curr->token[pos - 1])) || ftmp == 1)
		src = &(curr->p_info->stdout);
	else if (ftmp == 2)
		src = &(curr->p_info->stderr);
	else
		return (EXIT_FAILURE);
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
	else if ((**src = open(curr->token[pos + 1], O_TRUNC | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR)) == -1)
		return (EXIT_FAILURE);
	// free(curr->token[pos - 1]); //Eable when using Satkins'
	curr->token[(ftmp) ? pos - 1 : pos] = NULL;
	return (EXIT_SUCCESS);
}

int		handle_redirection(t_ast *curr)
{
	int	i;
	int	j;

	i = 0;
	while (curr->token[i])
	{
		j = 0;
		while (redir_ops[j].opflag)
		{
			if (!strcmp(curr->token[i], redir_ops[j].opflag))
			{
				if (redir_ops[j].func(curr, i))
				{
					printf("Failing.\n");
					return (EXIT_FAILURE);
				}
				printf("breaking\n");
				// return (EXIT_SUCCESS);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
