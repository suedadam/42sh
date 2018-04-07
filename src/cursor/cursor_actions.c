/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:59:21 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 19:51:00 by asyed            ###   ########.fr       */
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

void		cursor_to_left_margin(void)
{
	static char	*cache = NULL;

	if (!cache)
		cache = tgetstr("cm", NULL);
	tputs(tgoto(cache, 0, g_shell_env.cursor.og_position.y), 1, &my_putchar);
}
