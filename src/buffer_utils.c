/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:18:24 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/29 16:33:44 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			init_buffer(void)
{
	if (!(shell_env->buffer = (t_buffer *)ft_memalloc(sizeof(t_buffer)))
		|| !(buff = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			resize_buffer(t_buffer *buffer)
{
	// realloc buffer twize the size;
}

int			shift_buffer(t_buffer *buffer)
{

}

int			handle_buffer(void)
{

}
