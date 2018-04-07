/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:45:25 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/07 16:55:15 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			reset_buffer(void)
{
	free(g_shell_env.buffer->buff);
	g_shell_env.buffer->buff = NULL;
	free(g_shell_env.buffer);
	g_shell_env.buffer = NULL;
	free(g_shell_env.paperweight.buff);
	return (init_buffer());
}
