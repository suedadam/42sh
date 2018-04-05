/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_jump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:37:39 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 12:11:53 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void			jump_prev_word(t_cursor *cursor)
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

void			jump_next_word(t_cursor *cursor)
{
	while ((cursor->buffer[cursor->position]) != ' ' && cursor->position !=
			g_shell_env.buffer->length)
				cursor_to_right(cursor);
	while (cursor->buffer[cursor->position] == ' ' && cursor->position !=
			g_shell_env.buffer->length)
				cursor_to_right(cursor);
}

void			jump_next_line(t_cursor *cursor)
{
	if ((cursor->position + g_shell_env.window.ws_col) < g_shell_env.buffer->length)
		cursor->position += g_shell_env.window.ws_col;
	else
		cursor->position = g_shell_env.buffer->length;
	move_cursor(cursor);
}

void			jump_prev_line(t_cursor *cursor)
{
	if (cursor->position < g_shell_env.window.ws_col)
		cursor->position = 0;
	else
		cursor->position -= g_shell_env.window.ws_col;
	move_cursor(cursor);
}
