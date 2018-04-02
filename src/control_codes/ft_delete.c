/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:09:26 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/31 23:50:05 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		delete_last(int starting_position, t_cursor *cursor)
{
	cursor->position = g_shell_env.buffer->length;
	move_cursor(cursor);
	tputs(tgetstr("dc", 0), 1, &my_putchar);
	cursor->position = starting_position;
	move_cursor(cursor);
}

int			ft_delete(char byte)
{
	t_cursor	*cursor;
	char		*buffer;
	int			ret;

	byte = 'c';
	/*
	** !!!!!!!!!!!! Temporary solution !!!!!!!!!!!!!
	*/
	read(STDIN_FILENO, &byte, 1);
	/*
	** !!!!!!!!!!!! Temporary solution !!!!!!!!!!!!!
	*/
	ret = EXIT_SUCCESS;
	if (g_shell_env.buffer->length != g_shell_env.cursor.position)
	{	buffer = g_shell_env.buffer->buff;
		cursor = &(g_shell_env.cursor);
		ft_memmove(buffer + cursor->position, buffer + cursor->position + 1,
				g_shell_env.buffer->max_size - cursor->position - 1);
		ret = tputs(tgetstr("dc", 0), 1, &my_putchar);
		g_shell_env.buffer->length--;
		delete_last(cursor->position, cursor);
		update_buffer(buffer + cursor->position);
	}
	return (ret == ERR ? EXIT_FAILURE : EXIT_SUCCESS);
}
