/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:17:02 by satkins           #+#    #+#             */
/*   Updated: 2018/04/04 19:39:28 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "ast.h"

int	is_quote(t_parser *par, char cur_char)
{
	if (IS_QUOTE(cur_char))
	{
		if (!par->quoted)
			par->quoted = quoted_flags(cur_char);
		else
		{
			if (handle_embedded_quotes(&(par->quoted), cur_char, &(par->current_token)) == EXIT_FAILURE)
				return (0);
		}
		return (USED_CHAR);
	}
	else if (par->quoted & BACKSLASH)
	{
		if (!(par->current_token = strappend(&(par->current_token), '\\')))
			return (0);
	}
	return (UNUSED_CHAR);
}
