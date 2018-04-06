/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:46:38 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 11:21:57 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			resize_buffer(void)
{
	char	*newbuff;
	size_t	max_size;

	max_size = g_shell_env.buffer->max_size;
	if (!(newbuff = (char *)ft_strnew(sizeof(char) * (max_size + BUFF_SIZE))))
		return (EXIT_FAILURE);
	ft_memcpy(newbuff, g_shell_env.buffer->buff, max_size);
	free(g_shell_env.buffer->buff);
	g_shell_env.buffer->buff = newbuff;
	g_shell_env.cursor.buffer = g_shell_env.buffer->buff;
	g_shell_env.buffer->max_size = max_size + BUFF_SIZE;
	return (EXIT_SUCCESS);
}
