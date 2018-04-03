/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:41:08 by satkins           #+#    #+#             */
/*   Updated: 2018/04/03 15:25:43 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

uint8_t			quoted_flags(char c)
{
	if (c == '\'')
		return (SINGLE_QUOTE);
	else if (c == '\"')
		return (DOUBLE_QUOTE);
	else if (c == '\\')
		return (BACKSLASH);
	return (0);
}

int				handle_embedded_quotes(uint8_t *quoted,
	char **str, char **current_token)
{
	if (*quoted & DOUBLE_QUOTE)
	{
		if (*quoted & BACKSLASH)
		{
			if (!(**str == '\\' || **str == '\"'))
				if (!(*current_token = strappend(current_token, '\\')))
					return (EXIT_FAILURE);
			if (!(*current_token = strappend(current_token, **str)))
				return (EXIT_FAILURE);
			*quoted &= ~BACKSLASH;
		}
		else if (**str == '\\')
			*quoted |= BACKSLASH;
		else if (**str == '\"')
			*quoted &= ~DOUBLE_QUOTE;
		else if (**str == '\'' && !(*current_token = strappend(current_token, **str)))
			return (EXIT_FAILURE);
	}
	else if (*quoted & SINGLE_QUOTE)
	{		
		if (**str == '\'')
			*quoted &= ~SINGLE_QUOTE;
		else if (!(*current_token = strappend(current_token, **str)))
			return (EXIT_FAILURE);
	}
	else if (*quoted & BACKSLASH && (*current_token = strappend(current_token, **str))) //Change to ASCII value of character a/k/a \n instead of "\n"
		*quoted &= ~BACKSLASH;
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
