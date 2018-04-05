/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_locate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:38:18 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 11:38:32 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		cursor_locate(void)
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
