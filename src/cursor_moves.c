/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:57:48 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/04 11:55:14 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_term.h"

void	move_cursor(t_cursor *cursor)
{
	int		og_col;
	int		og_line;
	int		new_col;
	int		new_line;

	og_line = cursor->og_position.y;
	og_col = cursor->og_position.x;
	new_col = og_col + cursor->position;
	new_line = og_line + new_col / (g_shell_env.window.ws_col);
	new_col %= g_shell_env.window.ws_col;
	tputs(tgoto(tgetstr("cm", NULL),
		new_col, new_line), 0, &my_putchar);
}

void		locate_cursor(void)
{
	char	*temp;
	int		nln;
	int		o_winx;
	int		o_winy;

	temp = 0;
	o_winx = g_shell_env.cursor.og_screen.x;
	o_winy = g_shell_env.cursor.og_screen.y;
	nln = count_lines();
	get_window_size();
	get_cursor_first_position();
	g_shell_env.cursor.og_position.x = g_shell_env.cursor.og_position.x -
		((g_shell_env.buffer->length > (g_shell_env.prompt_length - o_winx)) ?
		 g_shell_env.prompt_length : g_shell_env.buffer->length);
	g_shell_env.cursor.og_position.y = g_shell_env.cursor.og_position.y - nln;
}
