/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:18:24 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/29 17:20:37 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			init_buffer(void)
{
	if (!(g_shell_env.buffer = (t_buffer *)ft_memalloc(sizeof(t_buffer))))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			resize_buffer()
{
	// realloc buffer twize the size;
	return (EXIT_SUCCESS);

}

int			shift_buffer(t_buffer *buffer)
{
	return (EXIT_SUCCESS);

}

int			handle_buffer(void)
{
	return (EXIT_SUCCESS);

}
