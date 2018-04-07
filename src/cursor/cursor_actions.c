/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:59:21 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/07 15:37:48 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		cursor_to_right(t_cursor *cursor)
{
	if (cursor->buffer_length != cursor->position)
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
	cursor->position = cursor->buffer_length;
	move_cursor(cursor);
}

void		cursor_to_left_margin(void)
{
	static char	*cache = NULL;

	if (!cache)
		cache = tgetstr("cm", NULL);
	tputs(tgoto(cache, 0, g_shell_env.cursor.og_position.y), 1, &my_putchar);
}
