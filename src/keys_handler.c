/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:24:01 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/07 18:32:18 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static int		(*multibyte_jump[])(char byte) = {
	ft_linemove,
	ft_delete,
	ft_shift,
	ft_alt,
	ft_scroll,
	ft_history,
	ft_page
};

static int		(*control_jump[])() = {
	control_a,
	NULL,
	NULL,
	NULL,
	control_e,
	NULL,
	control_c,
	control_h,
	NULL,
	control_j,
	control_k,
	control_l,
	control_m,
	NULL,
	control_o,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	control_u,
	control_v,
	control_w,
	NULL,
	control_y,
};

static inline __attribute__((always_inline)) int control_char(char byte)
{
	int	(*f)();

	if (byte > 127 || byte < 0)
		return (EXIT_SUCCESS);
	if (byte == 127)
		byte = 8;
	if (!(f = control_jump[(int)byte - 1]))
		return (EXIT_SUCCESS);
 	return ((*f)());
}

int		regular_text(char byte)
{
	t_cursor	*cursor;
	char		*buffer;

	cursor = &(g_shell_env.cursor);
	if (!(buffer = cursor->buffer))
		return (EXIT_FAILURE);
	if (g_shell_env.buffer->length == g_shell_env.buffer->max_size)
	{
		// printf("\nhey guys\n");
		if (resize_buffer() == EXIT_FAILURE)
			return (EXIT_FAILURE);
		tputs(tgetstr("bl", 0), 1, my_putchar);
		buffer = cursor->buffer;
	}
	ft_memmove(buffer + cursor->position + 1, buffer + cursor->position,
			cursor->buffer_length - cursor->position);
	buffer[cursor->position] = byte;
		g_shell_env.buffer->length++;
	cursor->buffer_length++;
	update_buffer(buffer + cursor->position, 1);
	return (EXIT_SUCCESS);
}

static int		one_byte(char byte)
{
	T_BSLASH = 0;
	if (byte == '\\')
		T_BSLASH = 1;
	else if (byte == '\''  && !T_DQUOTE)
		T_QUOTE = (T_QUOTE == 1) ? 0 : 1;
	else if (byte == '\"' && !T_QUOTE)
		T_DQUOTE = (T_DQUOTE == 1) ? 0 : 1;
	if (PRINTABLE(byte))
		return (regular_text(byte));
	else if (!PRINTABLE(byte))
		return (control_char(byte));
	return (EXIT_SUCCESS);
}

static int		multibyte(char byte)
{
	int	ret;

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
		return (multibyte_jump[ret](byte));
	}
	return (EXIT_FAILURE);
}

int				handle_keys(char byte)
{
	if (byte == 27 || T_MPASS)
		return (multibyte(byte));
	return (one_byte(byte));
}
