/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:57:48 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/04 16:21:18 by nkouris          ###   ########.fr       */
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

/* 
** Function to set true original positions after window resize events,
** and make sure that the way the cursor will react is the buffer is normal,
** wrapped and all
*/

void		locate_cursor(void)
{
	char	*temp;
	int		nln;
	int		o_curpos;

	temp = 0;
	o_curpos = g_shell_env.cursor.position;
	get_window_size();
	nln = count_lines();
	o_curpos = g_shell_env.cursor.og_screen.x / (o_curpos + g_shell_env.prompt_length);
	get_cursor_current_position();
	g_shell_env.cursor.og_position.x = g_shell_env.prompt_length;
	g_shell_env.cursor.og_position.y = g_shell_env.cursor.res_position.y - o_curpos;
}
