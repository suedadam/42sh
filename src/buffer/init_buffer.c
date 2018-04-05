/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:43:44 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 10:46:04 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			init_buffer(void)
{
	if (!(g_shell_env.buffer = (t_buffer *)ft_memalloc(sizeof(t_buffer)))
		|| !(g_shell_env.buffer->buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (EXIT_FAILURE);
	init_tokens();
	g_shell_env.paperweight.buff = 0;
	g_shell_env.cursor.buffer = g_shell_env.buffer->buff;
	g_shell_env.buffer->length = 0;
	g_shell_env.buffer->max_size = BUFF_SIZE;
	g_shell_env.cursor.position = 0;
	return (EXIT_SUCCESS);
}
