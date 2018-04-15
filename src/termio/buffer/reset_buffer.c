/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:45:25 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/14 22:42:30 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "ft_proto.h"

int			reset_buffer(void)
{
	free(g_shell_env.buffer->buff);
	g_shell_env.buffer->buff = NULL;
	free(g_shell_env.buffer);
	g_shell_env.buffer = NULL;
	free(g_shell_env.paperweight.buff);
	return (init_buffer());
}
