/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:19:02 by satkins           #+#    #+#             */
/*   Updated: 2018/04/14 01:05:10 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static void	skip_whitespace(char **input_str)
{
	if (!input_str)
		return ;
	while (IS_WHITESPACE(**input_str))
		(*input_str)++;
}

int			is_whitespc(t_parser *par, char **input_str)
{
	if (!par->quoted && IS_WHITESPACE(**input_str))
	{
		if (add_token(par->current_token, &(par->current_type), par)
			== EXIT_FAILURE)
			return (0);
		skip_whitespace(input_str);
		return (CONTINUE);
	}
	return (UNUSED_CHAR);
}
