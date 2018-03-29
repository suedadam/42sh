/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:57:48 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/29 16:38:24 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void	move_cursor(t_cursor *cursor)
{
	int		og_col;
	int		og_line;
	int		new_col;
	int		new_lin;

	og_col = cursor->og_position.y;
	og_line = cursor->og_position.x;

	new_lin = (og_line + cursor->position.x) % g_shell_env.window.ws_row;
	new_col = og_col + cursor->position.x +
		(og_line + cursor->position.x >= g_shell_env.window.ws_row);
	tputs(tgoto(tgetstr("cm", NULL), new_lin - 1, new_col - 1), 0, &my_putchar);
}

void		cursor_to_right(t_cursor *cursor)
{
	if (g_shell_env.buffer->len_buffer == cursor->pos.x)
	{
		cursor->position.x++;
		move_cursor(cursor);
	}
}

void		cursor_to_left(t_cursor *cursor)
{
	if (cursor->og_position.x == cursor->pos.x)
	{
		cursor->position.x--;
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

/*

int		ft_clearscreen(t_terminf *anti)
{
	char	*temp;

	temp = tgetstr("cl", 0);
	tputs(temp, 1, my_stupidput);
	anti = (void *)anti;
	new_prompt()
	return (EXIT_SUCCESS);
}

int		ft_backspace(t_terminf *anti)
{
	char	*temp;

	ft_curleft(anti);
	if (!(temp = tgetstr("dc", 0)))
		return (EXIT_FAILURE);
	tputs(temp, 1, my_stupidput);
	return (EXIT_SUCCESS);
}

// int		ft_delete(t_terminf *anti)
// {
// 	char	*temp;
//
// 	temp = tgetstr("dl", 0);
// 	tputs(temp, 1, my_stupidput);
// 	return (EXIT_SUCCESS);
// }


void	ft_clearline(int clr)
{
	char	*temp;

	clr = 0;
	temp = tgetstr("do", 0);
	tputs(temp, 1, my_stupidput);
	ft_printf("42sh%% ");
}

int		ft_passinput(t_terminf *anti)
{
	ft_clearline(0);
	anti = (void *)anti;
	return (EXIT_SUCCESS);
}
 */
