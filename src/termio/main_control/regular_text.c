/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:44:21 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/15 23:06:02 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maincontrol.h"
#include "ft_proto.h"

int		regular_text(char byte)
{
	t_cursor	*cursor;
	char		*buffer;

	hanging_byte(byte);
	cursor = &(g_shell_env.cursor);
	if (!(buffer = cursor->buffer))
		return (EXIT_FAILURE);
	if (g_shell_env.buffer->length == g_shell_env.buffer->max_size)
	{
		if (resize_buffer() == EXIT_FAILURE)
			return (EXIT_FAILURE);
		buffer = cursor->buffer;
	}
	ft_memmove(buffer + cursor->position + 1, buffer + cursor->position,
			cursor->buffer_length - cursor->position);
	buffer[cursor->position] = byte;
	g_shell_env.buffer->length++;
	cursor->buffer_length++;
	update_buffer(buffer + cursor->position, 1);
	return (EXIT_SUCCESS);
}
