/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanging_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:15:45 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 15:56:21 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hangingbyte.h"
#include "ft_proto.h"

void	hanging_byte(char byte)
{
	if (byte == '\'' && !T_DQUOTE)
		T_QUOTE = (T_QUOTE == 1) ? 0 : 1;
	else if (byte == '\"' && !T_QUOTE)
		T_DQUOTE = (T_DQUOTE == 1) ? 0 : 1;
	else if (byte == '(' || byte == ')')
		paren_check(byte);
	else if (byte == '{' || byte == '}')
		curly_check(byte);
	else if (byte == '|')
		T_PIPE = 1;
}
