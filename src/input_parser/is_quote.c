/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:17:02 by satkins           #+#    #+#             */
/*   Updated: 2018/04/18 22:53:08 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	quotes(t_parser *par, char cur_char)
{
	if (IS_QUOTE(cur_char))
	{
		if (!par->quoted)
		{
			if (!(par->quoted = quoted_flags(cur_char)))
				return (0);
			par->current_type = WORD;
		}
		else
		{
			if (handle_embedded_quotes(par, cur_char) == EXIT_FAILURE)
				return (0);
		}
		return (USED_CHAR);
	}
	else if ((par->quoted & BACKSLASH) && cur_char == '\n')
	{
		par->quoted &= ~BACKSLASH;
		return (USED_CHAR);
	}
	else if ((par->quoted & DOUBLE_QUOTE) && (par->quoted & BACKSLASH) && cur_char == 'n')
	{
		par->current_type = WORD;
		if (!(par->current_token = strappend(&(par->current_token), '\n')))
			return (0);
		par->quoted &= ~BACKSLASH;
		return (USED_CHAR);
	}
	return (UNUSED_CHAR);
}
