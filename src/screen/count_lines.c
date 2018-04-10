/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:03:27 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/09 19:51:35 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_screen.h"

int		count_lines(void)
{
	int		nln;

	nln = 0;
	if (g_shell_env.buffer->length)
		nln = (g_shell_env.buffer->length + g_shell_env.cursor.og_position.x) /
		g_shell_env.cursor.og_screen.x;
	return (nln);
}
