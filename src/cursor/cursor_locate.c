/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_locate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:38:18 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 19:52:56 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		cursor_locate(void)
{
	char	*temp;
	int		og_ln;
	int		res_ln;
	int		og_curpos;

	og_curpos = g_shell_env.cursor.position;
	cursor_to_home(&g_shell_env.cursor);
	get_window_size();
	get_cursor_first_position();
	clear_below();
	cursor_to_left_margin();
	new_prompt(0);
	reprint_buffer();
	g_shell_env.cursor.position = og_curpos;
	move_cursor(&g_shell_env.cursor);
	/* OLD
	temp = 0;
	og_ln = count_lines();
	get_window_size();
	if (g_shell_env.cursor.og_position.x < g_shell_env.cursor.og_screen.x)
	get_cursor_current_position();
	res_ln = count_lines();
	o_curpos = g_shell_env.cursor.position;
	o_curpos = g_shell_env.cursor.og_screen.x / (o_curpos + g_shell_env.prompt_length);
	get_cursor_current_position();
	g_shell_env.cursor.og_position.x = g_shell_env.prompt_length;
	g_shell_env.cursor.og_position.y = g_shell_env.cursor.res_position.y - o_curpos;
	*/
}
