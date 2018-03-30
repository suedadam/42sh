/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:06:38 by asyed             #+#    #+#             */
/*   Updated: 2018/03/29 18:24:10 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

struct s_redir_op	redir_ops[] = {
	// {"<", &ops_read_from},
	{">", &ops_redir_to},
	{">>", &ops_append_to},
	{NULL, NULL},
};

// int		ops_read_from(t_ast *curr, int pos)
// {
// 	curr->p_info->stdin
// }

int		ops_append_to(t_ast *curr, int pos)
{
	int		ftmp;
	int		dtmp;
	int		*src;

	if (!(ftmp = ft_atoi(curr->token[pos - 1])))
		ftmp = 1;
	if (ftmp == 1)
		src = curr->p_info->stdout;
	else if (ftmp == 2)
		src = &(curr->p_info->stderr);
	else
		return (EXIT_FAILURE);
	if (*(curr->token[pos + 1]) == '&')
	{
		dtmp = ft_atoi(&(curr->token[pos + 1][1]));
		if (dtmp == 1)
			*src = *(curr->p_info->stdout);
		else if (dtmp == 2)
			*src = curr->p_info->stderr;
		else
			return (EXIT_FAILURE);
	}
	else if ((*src = open(curr->token[pos + 1], O_APPEND | O_CREAT | O_WRONLY)) == -1)
		return (EXIT_FAILURE);
	// free(curr->token[pos - 1]); //Eable when using Satkins'
	curr->token[pos - 1] = NULL;
	return (EXIT_SUCCESS);
}

int		ops_redir_to(t_ast *curr, int pos)
{
	int		ftmp;
	int		dtmp;
	int		*src;

	if (!(ftmp = ft_atoi(curr->token[pos - 1])))
		ftmp = 1;
	if (ftmp == 1)
		src = curr->p_info->stdout;
	else if (ftmp == 2)
		src = &(curr->p_info->stderr);
	else
		return (EXIT_FAILURE);
	if (*(curr->token[pos + 1]) == '&')
	{
		dtmp = ft_atoi(&(curr->token[pos + 1][1]));
		if (dtmp == 1)
			*src = *(curr->p_info->stdout);
		else if (dtmp == 2)
			*src = curr->p_info->stderr;
		else
			return (EXIT_FAILURE);
	}
	else if ((*src = open(curr->token[pos + 1], O_TRUNC | O_CREAT | O_WRONLY)) == -1)
		return (EXIT_FAILURE);
	// free(curr->token[pos - 1]); //Eable when using Satkins'
	curr->token[pos - 1] = NULL;
	return (EXIT_SUCCESS);
}

int		handle_redirection(t_ast *curr)
{
	int	i;
	int	j;

	i = 0;
	printf("Got here.\n");
	while (curr->token[i])
	{
		j = 0;
		while (redir_ops[j].opflag)
		{
			if (!strcmp(curr->token[i], redir_ops[j].opflag))
			{
				if (redir_ops[j].func(curr, i))
					return (EXIT_FAILURE);
				// return (EXIT_SUCCESS);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

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
