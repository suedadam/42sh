/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_navigation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:18:41 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/04 21:06:11 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void			move_prev_word(t_cursor *cursor)
{
	if ((cursor->position && (cursor->buffer[cursor->position]) != ' '
		&& cursor->buffer[cursor->position - 1] == ' ')
			|| cursor->position == g_shell_env.buffer->length)
		cursor_to_left(cursor);
	while (cursor->position && cursor->buffer[cursor->position] == ' ')
		cursor_to_left(cursor);
	while (cursor->position && (cursor->buffer[cursor->position]) != ' ')
		cursor_to_left(cursor);
	if (cursor->position)
		cursor_to_right(cursor);
}

void			move_next_word(t_cursor *cursor)
{
	while ((cursor->buffer[cursor->position]) != ' ' && cursor->position !=
			g_shell_env.buffer->length)
				cursor_to_right(cursor);
	while (cursor->buffer[cursor->position] == ' ' && cursor->position !=
			g_shell_env.buffer->length)
				cursor_to_right(cursor);
}

void			move_next_line(t_cursor *cursor)
{
	if ((cursor->position + g_shell_env.window.ws_col) < g_shell_env.buffer->length)
		cursor->position += g_shell_env.window.ws_col;
	else
		cursor->position = g_shell_env.buffer->length;
	move_cursor(cursor);
}

void			move_prev_line(t_cursor *cursor)
{
	if (cursor->position < g_shell_env.window.ws_col)
		cursor->position = 0;
	else
		cursor->position -= g_shell_env.window.ws_col;
	move_cursor(cursor);
}
