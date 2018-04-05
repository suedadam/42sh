/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_semicolon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:16:05 by satkins           #+#    #+#             */
/*   Updated: 2018/04/04 20:16:47 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static int		end_statement(char *curr_token, t_token_type *current_type,
	t_parser *par)
{
	t_token_type	tmp;

	tmp = operator;
	if (add_token(curr_token, current_type, par) == EXIT_FAILURE
		|| add_token(";", &tmp, par) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				is_semi(t_parser *par, char cur_char)
{
	if (!par->quoted && cur_char == ';')
	{
		if (end_statement(par->current_token, &(par->current_type),
			par) == EXIT_FAILURE)
			return (0);
		return (USED_CHAR);
	}
	return (UNUSED_CHAR);
}
