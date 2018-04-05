/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_navigation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:18:41 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/04 19:37:59 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void			move_prev_word(t_cursor *cursor)
{
	if (cursor->position && ft_isalnum(cursor->buffer[cursor->position]))
	{
		while (cursor->position && cursor->buffer[cursor->position] != ' ')
			cursor_to_left(cursor);
		if (cursor->position)
			cursor_to_right(cursor);
	}
	else if (cursor->position)
	{
		while (cursor->position && cursor->buffer[cursor->position] == ' ')
			cursor_to_left(cursor);
		move_prev_word(cursor);
	}
}

void			move_next_word(t_cursor *cursor)
{
	if (cursor->position != g_shell_env.buffer->length && ft_isalnum(cursor->buffer[cursor->position]))
	{
		while (cursor->buffer[cursor->position] != ' ')
			cursor_to_right(cursor);
		move_next_word(cursor);
	}
	else if (cursor->position != g_shell_env.buffer->length)
		while (cursor->position != g_shell_env.buffer->length
				&& cursor->buffer[cursor->position] == ' ')
			cursor_to_right(cursor);
}

void			move_next_line(t_cursor *cursor)
{
	if (cursor->position + g_shell_env.window.ws_col >
			g_shell_env.buffer->length)
		cursor->position += g_shell_env.window.ws_col;
	else
		cursor->position = g_shell_env.buffer->length;
	move_cursor(cursor);
}

void			move_prev_line(t_cursor *cursor)
{
	if (cursor->position + cursor->og_position.x < g_shell_env.window.ws_col)
		cursor->position = 0;
	else
		cursor->position -= g_shell_env.window.ws_col;
	move_cursor(cursor);
}
