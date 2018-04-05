/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:45:25 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 10:48:01 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			reset_buffer(void)
{
	int	ret;

	free(g_shell_env.buffer->buff);
	free(g_shell_env.buffer);
	ret = init_buffer();
	return (ret);
}
