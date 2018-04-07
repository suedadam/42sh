/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:46:38 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/07 15:28:17 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			resize_buffer(void)
{
	t_cursor	*cursor;
	char		*new_buffer;
	char		*old_buffer;
	size_t		max_size;
	size_t		offset;

	max_size = g_shell_env.buffer->max_size;
	old_buffer = 0;
	if (!(new_buffer = (char *)ft_memalloc(sizeof(char) * (max_size * 2 + 1))))
		return (EXIT_FAILURE);
	ft_memmove(new_buffer, g_shell_env.buffer->buff, max_size);
	g_shell_env.buffer->max_size *= 2;
	cursor = &(g_shell_env.cursor);
	offset = cursor->buffer - g_shell_env.buffer->buff;
	free(old_buffer);
	old_buffer = 0;
	g_shell_env.buffer->buff = new_buffer;
	cursor->buffer = new_buffer + offset;
	return (EXIT_SUCCESS);
}


// int			resize_buffer(void)
// {
// 	char		*newbuff;
// 	char		*oldbuff;
// 	t_cursor	*cursor;
// 	size_t		max_size;
// 	size_t		length;
//
// 	cursor = g_shell_env.cursor;
// 	if (!(oldbuff = cursor->buffer))
// 		return (EXIT_FAILURE);
// 	max_size = g_shell_env.buffer->max_size;
// 	length = g_shell_env.buffer->length;
// 	if (!(newbuff = (char *)ft_memalloc(sizeof(char) * (2 * length))))
// 		return (EXIT_FAILURE);
// 	ft_memcpy(newbuff, g_shell_env.buffer->buff, length);
// 	free(g_shell_env.buffer->buff);
// 	g_shell_env.buffer->buff = 0;
// 	g_shell_env.buffer->buff = newbuff;
// 	 = g_shell_env.buffer->buff;
// 	g_shell_env.buffer->max_size += length;
// 	return (EXIT_SUCCESS);
// }
