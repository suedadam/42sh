/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:35:13 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/01 20:05:19 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		update_end_of_screen(void)
{
	if (g_shell_env.cursor.og_position.y + (g_shell_env.cursor.og_position.x  +
		g_shell_env.buffer->length) / g_shell_env.window.ws_col
			>= g_shell_env.window.ws_row)
	{
		g_shell_env.cursor.og_position.y--;
		ft_putchar_fd('\n', 0);
	}
}



void		update_buffer(char *buffer)
{
	int		i;
	size_t	position;

	i = 0;
	position = g_shell_env.cursor.position;
	/*
	** putstr ?
	*/
	while (buffer[i])
	{
		ft_putchar_fd(buffer[i], 0);
		i++;
	}
	update_end_of_screen();
	g_shell_env.cursor.position = position;
	move_cursor(&g_shell_env.cursor);
}
