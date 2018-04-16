/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:24:01 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/16 02:50:53 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maincontrol.h"
#include "ft_proto.h"

/*
**	byte == 127 reassaign for redirect to backspace
*/

static inline __attribute__((always_inline)) int	control_char(char byte)
{
	int	(*f)();

	if (byte > 127 || byte <= 0)
		return (EXIT_SUCCESS);
	if (byte == 127)
		byte = 8;
	if (!(f = g_control_jump[(int)byte - 1]))
		return (EXIT_SUCCESS);
	return ((*f)());
}

static int											one_byte(char byte)
{
	if (!IS_WHITESPACE(byte))
		T_PIPE = 0;
	if (PRINTABLE(byte))
		return (regular_text(byte));
	else if (!PRINTABLE(byte) || byte == 127)
		return (control_char(byte));
	return (EXIT_SUCCESS);
}

static int											multibyte(char byte)
{
	int	ret;

	T_PIPE = 0;
	if (T_MPASS == 0
		|| (T_MPASS == 1 && byte == '['))
	{
		(T_MPASS)++;
		return (EXIT_SUCCESS);
	}
	else if (T_MPASS == 1 && (byte != '[' && byte != 27))
	{
		T_MPASS = 0;
		return (one_byte(byte));
	}
	if (T_MPASS == 1 && byte == 27)
		T_DBLESC = 1;
	if ((ret = multibyte_dispatch(byte)) >= 0)
	{
		T_MPASS = 0;
		return (g_multibyte_jump[ret](byte));
	}
	return (EXIT_FAILURE);
}

int													handle_keys(char byte)
{
	if (byte == 27 || T_MPASS)
		return (multibyte(byte));
	return (one_byte(byte));
}
