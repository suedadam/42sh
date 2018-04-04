/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrn_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:02:56 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/03 17:27:04 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		get_window_size(void)
{
	if ((ioctl(0, TIOCGWINSZ, &g_shell_env.window)) < 0)
		return (EXIT_FAILURE);
	g_shell_env.cursor.og_screen.x = g_shell_env.window.ws_col;
	g_shell_env.cursor.og_screen.y = g_shell_env.window.ws_row;
	return (EXIT_SUCCESS);
}

void	window_resize(int c)
{
	c = 0;
	resize_prompt();
}

/*
void	relative_move_cusor(t_cursor *cursor)
{
	int		og_col;
	int		og_line;
	int		new_col;
	int		new_line;

	og_line = cursor->og_position.y + (g_shell_env.window.ws_row - cursor->ogog_col = cursor->og_position.x + (g_shell_env.window.ws_col - cursor->og_position.x);
	new_col = og_col + cursor->position;
	new_line = og_line + new_col / (g_shell_env.window.ws_col);
	new_col %= g_shell_env.window.ws_col;
	tputs(tgoto(tgetstr("cm", NULL),
		new_col, new_line), 0, &my_putchar);
}
*/
