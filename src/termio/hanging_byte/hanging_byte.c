/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanging_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:15:45 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/20 16:32:10 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hangingbyte.h"
#include "ft_proto.h"

void	verify_hanging(void)
{
	char	*buf;

	buf = g_shell_env.buffer->buff;
	ft_bzero(&g_shell_env.tokens, sizeof(t_tokens));
	while (*buf)
	{
		if (*buf == '\\' && *(buf + 1))
		{
			buf += 2;
			continue ;
		}
		hanging_byte(*buf);
		if (!IS_WHITESPACE(*buf) && *buf != '|')
			T_PIPE = 0;
		buf++;
	}
}

void	hanging_byte(char byte)
{
	if (byte == '\'' && (!T_DQUOTE))
		T_QUOTE = (T_QUOTE == 1) ? 0 : 1 * !T_DQUOTE;
	else if (byte == '\"' && (!T_QUOTE))
		T_DQUOTE = (T_DQUOTE == 1) ? 0 : 1 * !T_QUOTE;
	else if (byte == '(' || byte == ')')
		paren_check(byte);
	else if (byte == '{' || byte == '}')
		curly_check(byte);
	else if (byte == '|')
		T_PIPE = 1;
}
