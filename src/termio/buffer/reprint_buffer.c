/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reprint_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:47:14 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/15 16:17:29 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "ft_proto.h"

int			reprint_buffer(void)
{
	ft_putstr_fd(g_shell_env.buffer->buff, STDIN_FILENO);
	move_cursor(&g_shell_env.cursor);
	g_shell_env.cursor.buffer_length = g_shell_env.buffer->length;
	return (EXIT_SUCCESS);
}
