/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:59:21 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/03 17:27:18 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		cursor_to_right(t_cursor *cursor)
{
	if (g_shell_env.buffer->length != cursor->position)
	{
		cursor->position++;
		move_cursor(cursor);
	}
}

void		cursor_to_left(t_cursor *cursor)
{
	if (cursor->position > 0)
	{
		cursor->position--;
		move_cursor(cursor);
	}
}

void		cursor_to_home(t_cursor *cursor)
{
	cursor->position = 0;
	move_cursor(cursor);
}

void		cursor_to_end(t_cursor *cursor)
{
	cursor->position = g_shell_env.buffer->length;
	move_cursor(cursor);
}
