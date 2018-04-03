/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:38:47 by satkins           #+#    #+#             */
/*   Updated: 2018/04/03 16:30:03 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int					add_token(char *curr_token, t_token_type *curr_type,
	t_parser *par)
{
	int				i;

	if (!curr_token || !curr_type || *curr_type == null)
		return (EXIT_SUCCESS);
	i = 0;
	while ((par->tokens)[i])
	{
		// printf("i : %d\n", i);
		++i;
	}
	// if (i >= 0)
	// {
		// printf("%s\n", "boobs2");
		if (!(par->tokens = (char **)realloc(par->tokens, sizeof(char *) * (i + 2)))
			|| !(par->types = realloc(par->types, sizeof(t_token_type) * (i + 2))))
			return (EXIT_FAILURE);
	// }
	// else if (!(tokens = ft_memalloc(sizeof(char *) * 2)) // this elif may be deleted depending on implementation of realloc
	// 	|| !(types = ft_memalloc(sizeof(t_token_type) * 2)))
	// 	return (EXIT_FAILURE);
	if (!((par->tokens)[i] = ft_strdup(curr_token))
		|| !ft_memcpy(&((par->types)[i]), curr_type, sizeof(t_token_type)))
	{
			// printf("%s\n", "boobs3");
			return (EXIT_FAILURE);
	}
	(par->tokens)[i + 1] = NULL;
	(par->types)[i + 1] = null;
	if (*curr_token != ';')
	{
		ft_memset(curr_token, 0, ft_strlen(curr_token));
		*curr_type = null;
	}
	return (EXIT_SUCCESS);
}
