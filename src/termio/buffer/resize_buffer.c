/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:46:38 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 11:08:03 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "ft_proto.h"

int			resize_buffer(void)
{
	t_cursor	*cursor;
	char		*new_buffer;
	size_t		max_size;
	size_t		offset;

	max_size = g_shell_env.buffer->max_size;
	if (!(new_buffer = (char *)ft_memalloc(sizeof(char) * (max_size * 2 + 1))))
		return (EXIT_FAILURE);
	ft_memmove(new_buffer, g_shell_env.buffer->buff, max_size);
	g_shell_env.buffer->max_size *= 2;
	cursor = &(g_shell_env.cursor);
	offset = cursor->buffer - g_shell_env.buffer->buff;
	meta_free(g_shell_env.buffer->buff);
	g_shell_env.buffer->buff = new_buffer;
	cursor->buffer = new_buffer + offset;
	return (EXIT_SUCCESS);
}
