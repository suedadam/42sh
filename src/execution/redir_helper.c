/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:06:38 by asyed             #+#    #+#             */
/*   Updated: 2018/04/16 18:21:35 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	*ref_picker(t_ast *curr, int fd)
{
	if (fd == 1)
		return (&(curr->p_info->stdout));
	else if (fd == 2)
		return (&(curr->p_info->stderr));
	return (NULL);
}

void	*valid_input(char *token, char exception, t_ast *curr)
{
	int	i;

	i = 0;
	if (!token)
		return (NULL);
	while (token[i])
	{
		if ((token[i] < '0' || token[i] > '9') && token[i] != exception)
			return (NULL);
		i++;
	}
	return (ref_picker(curr, ft_atoi(token)));
}

int		free_after(t_ast *curr, int pos)
{
	meta_free(curr->token[pos + 1]);
	curr->token[pos + 1] = NULL;
	meta_free(curr->token[pos]);
	curr->token[pos] = NULL;
	return (EXIT_SUCCESS);
}
