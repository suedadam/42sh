/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:35:13 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/05 12:01:28 by nkouris          ###   ########.fr       */
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
