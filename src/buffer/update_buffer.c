/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:00:49 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/07 16:33:20 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		update_buffer(char *buffer, int inc)
{
	size_t	position;

	if (buffer)
	{
		position = g_shell_env.cursor.position;
		ft_putstr_fd(buffer, STDIN_FILENO);
		update_end_of_screen();
		g_shell_env.cursor.position = position + inc;
		move_cursor(&g_shell_env.cursor);
	}
}
