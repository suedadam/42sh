/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:41:08 by satkins           #+#    #+#             */
/*   Updated: 2018/04/14 00:47:21 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

uint8_t		quoted_flags(char c)
{
	if (c == '\'')
		return (SINGLE_QUOTE);
	else if (c == '\"')
		return (DOUBLE_QUOTE);
	else if (c == '\\')
		return (BACKSLASH);
	return (0);
}

static int	dquote_mode(uint8_t *quoted,
	char cur_char, char **current_token)
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
	else if (cur_char == '\'' &&
		!(*current_token = strappend(current_token, cur_char)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	squote_mode(uint8_t *quoted,
	char cur_char, char **current_token)
{
	if (cur_char == '\'')
		*quoted &= ~SINGLE_QUOTE;
	else if (!(*current_token = strappend(current_token, cur_char)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			handle_embedded_quotes(t_parser *par, char cur_char)
{
	if (par->quoted & DOUBLE_QUOTE)
		return (dquote_mode(&(par->quoted), cur_char, &(par->current_token)));
	else if (par->quoted & SINGLE_QUOTE)
		return (squote_mode(&(par->quoted), cur_char, &(par->current_token)));
	else if (par->quoted & BACKSLASH)
	{
		par->current_type = WORD;
		if (!(par->current_token = strappend(&(par->current_token), cur_char)))
			return (EXIT_FAILURE);
		par->quoted &= ~BACKSLASH;
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}
