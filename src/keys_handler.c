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

	ft_linemove
	/*

	ft_backspace,
	ft_scroll,
	ft_history,
	ft_shiftmod
	*/
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
	cursor->position++;
	g_shell_env.buffer->length++;
	tputs(tgetstr("im", 0), 1, &my_putchar);
	tputs(tgetstr("ic", 0), 1, &my_putchar);
	ft_putchar_fd(byte, 0);
	tputs(tgetstr("ip", 0), 1, &my_putchar);
	tputs(tgetstr("ei", 0), 1, &my_putchar);
	return (ret);
}

static int		one_byte(char byte)
{
	int		ret;

	ret = EXIT_SUCCESS;
	if (byte == '\\')
		g_shell_env.tokens.bslash = 1;
	if (byte >= 32 && byte <= 126)
		ret = regular_text(byte);
	else if (byte < 32 || byte == 127)
		ret = control_char(byte);
	return (ret);
}

static int		multibyte(char byte)
{
	int	ret;

	if (g_shell_env.tokens.mpass == 0
		|| (g_shell_env.tokens.mpass == 1 && byte == '['))
	{
		(g_shell_env.tokens.mpass)++;
		return (EXIT_SUCCESS);
	}
	else if (g_shell_env.tokens.mpass == 1 && byte != '[')
	{
		one_byte(byte);
		g_shell_env.tokens.mpass = 0;
		return (EXIT_SUCCESS);
	}
	if ((ret = multibyte_dispatch(byte)) != EXIT_FAILURE)
	{
		if (ret == CURSOR_MOVE)
			multibyte_jump[ret](byte);
	}
	else
		return (EXIT_FAILURE);
	g_shell_env.tokens.mpass = 0;
	return (EXIT_SUCCESS);
}

int				handle_keys(char byte)
{
	int		ret;
	int		token;

	ret = EXIT_SUCCESS;
	token = 0;
	if (byte == 27 || g_shell_env.tokens.mpass)
		ret = multibyte(byte);
	else
		ret = one_byte(byte);
	return (ret);
}
