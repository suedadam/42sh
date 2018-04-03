/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2018/03/29 15:43:13 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static int		(*multibyte_jump[])(char byte) = {
	ft_linemove,
	ft_delete,
/*	ft_scroll,*/0,
/*	ft_history,*/0,
/*	ft_shiftmod*/0
};

static int		(*control_jump[])() = {
	control_a,
	control_e,
	control_g,
	control_h,
	control_j,
	control_l,
	control_m,
	control_o,
	control_v,
	control_w
};

static int		control_char(char byte)
{
	int	ret;

	if ((ret = control_dispatch(byte)) < 0)
		return (EXIT_FAILURE);
	else
		ret = control_jump[ret]();
  return (ret == EXIT_SUCCESS ? EXIT_SUCCESS : EXIT_FAILURE);
}

static int		regular_text(char byte)
{
	t_cursor	*cursor;
	char		*buffer;
	int			ret;

	ret = EXIT_SUCCESS;
	buffer = g_shell_env.buffer->buff;
	cursor = &(g_shell_env.cursor);
	if (g_shell_env.buffer->length == g_shell_env.buffer->max_size)
		ret = resize_buffer();
	ft_memmove(buffer + cursor->position + 1, buffer + cursor->position,
			g_shell_env.buffer->max_size - cursor->position - 1);
	buffer[cursor->position] = byte;
	g_shell_env.buffer->length++;
	update_buffer(buffer + cursor->position);
	// update_end_of_screen();
	cursor->position++;
	move_cursor(cursor);
	return (ret);
}

static int		one_byte(char byte)
{
	int		ret;

	ret = EXIT_SUCCESS;
	if (T_BSLASH)
		T_BSLASH = 0;
	if (byte == '\\')
		T_BSLASH = 1;
	else if (byte == '\'')
		(T_QUOTE == 1) ? (T_QUOTE = 0) : (T_QUOTE = 1);
	else if (byte == '\"')
		(T_DQUOTE == 1) ? (T_DQUOTE = 0) : (T_DQUOTE = 1);
	if (byte >= 32 && byte <= 126)
		ret = regular_text(byte);
	else if (byte < 32 || byte == 127)
		ret = control_char(byte);
	return (ret);
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
	else if (T_MPASS == 1 && byte != '[')
	{
		one_byte(byte);
		T_MPASS = 0;
		return (EXIT_SUCCESS);
	}
	if ((ret = multibyte_dispatch(byte)) >= 0)
		multibyte_jump[ret](byte);
	else
		return (EXIT_FAILURE);
	T_MPASS = 0;
	return (EXIT_SUCCESS);
}

int				handle_keys(char byte)
{
	int		ret;
	int		token;

	ret = EXIT_SUCCESS;
	token = 0;
	if (byte == 27 || T_MPASS)
		ret = multibyte(byte);
	else
		ret = one_byte(byte);
	return (ret);
}
