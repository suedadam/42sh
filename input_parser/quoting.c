/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:41:08 by satkins           #+#    #+#             */
/*   Updated: 2018/04/04 10:32:26 by satkins          ###   ########.fr       */
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
	char cur_char, char **current_token)
{
	if (*quoted & DOUBLE_QUOTE)
	{
		if (*quoted & BACKSLASH)
		{
			if (!(cur_char == '\\' || cur_char == '\"'))
				if (!(*current_token = strappend(current_token, '\\')))
					return (EXIT_FAILURE);
			if (!(*current_token = strappend(current_token, cur_char)))
				return (EXIT_FAILURE);
			*quoted &= ~BACKSLASH;
		}
		else if (cur_char == '\\')
			*quoted |= BACKSLASH;
		else if (cur_char == '\"')
			*quoted &= ~DOUBLE_QUOTE;
		else if (cur_char == '\'' && !(*current_token = strappend(current_token, cur_char)))
			return (EXIT_FAILURE);
	}
	else if (*quoted & SINGLE_QUOTE)
	{		
		if (cur_char == '\'')
			*quoted &= ~SINGLE_QUOTE;
		else if (!(*current_token = strappend(current_token, cur_char)))
			return (EXIT_FAILURE);
	}
	else if (*quoted & BACKSLASH && (*current_token = strappend(current_token, cur_char))) //Change to ASCII value of character a/k/a \n instead of "\n"
		*quoted &= ~BACKSLASH;
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
