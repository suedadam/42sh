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

static int		regular_text(char byte)
{
	t_cursor	*cursor;
	char		*buffer;
	int			ret;

	ret = EXIT_SUCCESS;
	cursor = &(g_shell_env.cursor);
	buffer = g_shell_env.buffer->buff;
	if (g_shell_env.buffer->length == g_shell_env.buffer->max_size)
		ret = resize_buffer();
	ft_memmove(&buffer[cursor->position + 1], &buffer[cursor->position],
			g_shell_env.buffer->length - cursor->position);
	tputs(tgetstr("im", 0), 1, &my_putchar);
	ft_putchar_fd(byte, 0);
	tputs(tgetstr("ei", 0), 1, &my_putchar);
	return (ret);
}

static int		control_char(char byte)
{
	// jump table
	return (EXIT_SUCCESS);
}

static int		one_byte(char byte)
{
	int		ret;

	ret = EXIT_SUCCESS;
	if (byte >= 32 && byte <= 126)
		ret = regular_text(byte);
	if (byte < 32 || byte == 127)
		ret = control_char(byte);
	return (ret);
}

static int		multibyte(char byte, int *mpass)
{
	if (*mpass == 0
		|| (*mpass == 1 && byte == '['))
	{
		(*mpass)++;
		return (EXIT_SUCCESS);
	}
	else if (*mpass == 1 && byte != '[')
	{
		one_byte(byte);
		return (EXIT_SUCCESS);
	}
	// jump table
	return (EXIT_SUCCESS);
}


int				handle_keys(char byte, int *mpass)
{
	int		ret;
	int		token;

	ret = EXIT_SUCCESS;
	token = 0;
	if (byte == 27)
		ret = multibyte(byte, mpass);
	else
		ret = one_byte(byte);
	return (ret);
}
