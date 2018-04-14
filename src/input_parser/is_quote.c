/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:17:02 by satkins           #+#    #+#             */
/*   Updated: 2018/04/14 00:46:53 by satkins          ###   ########.fr       */
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
	return (UNUSED_CHAR);
}
