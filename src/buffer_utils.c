/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:18:24 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/01 19:32:14 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			init_buffer(void)
{
	if (!(g_shell_env.buffer = (t_buffer *)ft_memalloc(sizeof(t_buffer)))
		|| !(g_shell_env.buffer->buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (EXIT_FAILURE);
	g_shell_env.buffer->length = 0;
	g_shell_env.buffer->max_size = BUFF_SIZE;
	g_shell_env.cursor.position = 0;
	return (EXIT_SUCCESS);
}

int			resize_buffer(void)
{
	// realloc buffer twize the size;
	return (EXIT_SUCCESS);

}

int			shift_buffer(t_buffer *buffer)
{
	buffer  = (void *)buffer;
	return (EXIT_SUCCESS);

}

int			reset_buffer(void)
{
	int	ret;

	free(g_shell_env.buffer->buff);
	free(g_shell_env.buffer);
	ret = init_buffer();
	return (ret);
}

int			reprint_buffer(void)
{
	ft_printf("%s", g_shell_env.buffer->buff);
	move_cursor(&g_shell_env.cursor);
	return (EXIT_SUCCESS);
}
