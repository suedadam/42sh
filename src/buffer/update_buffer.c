/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:00:49 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 17:21:58 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		update_buffer(char *buffer)
{
	int		i;
	size_t	position;

	i = 0;
	position = g_shell_env.cursor.position;
	/*
	** putstr ?
	*/
	if (buffer)
	{
		while (buffer && buffer[i])
		{
			ft_putchar_fd(buffer[i], 0);
			i++;
		}
		update_end_of_screen();
		g_shell_env.cursor.position = position;
		move_cursor(&g_shell_env.cursor);
	}
}
