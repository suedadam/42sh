/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:19:43 by satkins           #+#    #+#             */
/*   Updated: 2018/04/04 20:15:41 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int				start_word(t_parser *par, char cur_char)
{
	par->current_type = word;
	if (!(par->current_token = strappend(&(par->current_token), cur_char)))
		return (0);
	par->quoted &= ~BACKSLASH;
	return (USED_CHAR);
}

int				is_comment(t_parser *par, char cur_char)
{
	if (cur_char == '#')
		return (BREAK);
	return (UNUSED_CHAR);
}

int				is_word(t_parser *par, char cur_char)
{
	if (par->current_type == word)
	{
		if (!(par->current_token = strappend(&(par->current_token), cur_char)))
			return (0);
		par->quoted &= ~BACKSLASH;
		return (USED_CHAR);
	}
	return (UNUSED_CHAR);
}
