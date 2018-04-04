/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrn_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:02:56 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/04 13:49:05 by nkouris          ###   ########.fr       */
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
	//get_window_size();
	locate_cursor();
//	resize_prompt();
}
