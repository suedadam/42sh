/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:09:26 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/18 20:13:17 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_escape.h"
#include "ft_proto.h"

void		delete_last(int starting_position, t_cursor *cursor)
{
	size_t		length;

	length = cursor->buffer_length;
	cursor->position = length;
	cursor->buffer[length] = 0;
	move_cursor(cursor);
	ft_putchar_fd(' ', 0);
	cursor->position = starting_position;
	move_cursor(cursor);
}

int			ft_delete(char byte)
{
	t_cursor	*cursor;
	char		*buffer;
	static char	*cache = NULL;

	!cache ? cache = tgetstr("dc", NULL) : 0;
	if (byte > 0)
	{
		if (read(STDIN_FILENO, &byte, 1) < 0)
			return (EXIT_FAILURE);
	}
	cursor = &(g_shell_env.cursor);
	if (!(buffer = cursor->buffer))
		return (EXIT_FAILURE);
	if (cursor->buffer_length != cursor->position)
	{
		ft_memmove(buffer + cursor->position, buffer + cursor->position + 1,
				cursor->buffer_length - cursor->position);
		tputs(cache, 1, &my_putchar);
		g_shell_env.buffer->length--;
		cursor->buffer_length--;
		delete_last(cursor->position, cursor);
		update_buffer(buffer + cursor->position, 0);
	}
	return (EXIT_SUCCESS);
}
