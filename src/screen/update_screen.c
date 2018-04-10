/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:35:13 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/09 19:38:11 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_screen.h"

void		update_end_of_screen(void)
{
	if (g_shell_env.cursor.og_position.y + (g_shell_env.cursor.og_position.x +
		g_shell_env.buffer->length) / g_shell_env.window.ws_col
		>= g_shell_env.window.ws_row)
	{
		g_shell_env.cursor.og_position.y--;
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}
