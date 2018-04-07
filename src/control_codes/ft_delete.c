/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:09:26 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/06 18:40:26 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		delete_last(int starting_position, t_cursor *cursor)
{
	size_t		length;

	length = g_shell_env.buffer->length;
	cursor->position = length;
	g_shell_env.buffer->buff[length] = 0;
	move_cursor(cursor);
	ft_putchar_fd(' ', 0);
	cursor->position = starting_position;
	move_cursor(cursor);
}

int			ft_delete(char byte)
{
	t_cursor	*cursor;
	char		*buffer;
	int			ret;

	/*
	** !!!!!!!!!!!! Temporary solution !!!!!!!!!!!!!
	*/
	if (byte > 0)
	{
		if (read(STDIN_FILENO, &byte, 1) < 0)
			return (EXIT_FAILURE);
	}
	/*
	** !!!!!!!!!!!! Temporary solution !!!!!!!!!!!!!
	*/
	ret = EXIT_SUCCESS;
	if (g_shell_env.buffer->length != g_shell_env.cursor.position)
	{	buffer = g_shell_env.buffer->buff;
		cursor = &(g_shell_env.cursor);
		ft_memmove(buffer + cursor->position, buffer + cursor->position + 1,
				g_shell_env.buffer->max_size - cursor->position);
		ret = tputs(tgetstr("dc", 0), 1, &my_putchar);
		g_shell_env.buffer->length--;
		delete_last(cursor->position, cursor);
		// cursor->position--;
		update_buffer(buffer + cursor->position, 0);
	}
	return (ret == ERR ? EXIT_FAILURE : EXIT_SUCCESS);
}
