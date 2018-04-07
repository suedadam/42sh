/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:03:27 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/07 15:40:20 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		count_lines(void)
{
	int		nln;

	nln = 0;
	if (g_shell_env.buffer->length)
		nln =  (g_shell_env.buffer->length + g_shell_env.cursor.og_position.x) /
			g_shell_env.cursor.og_screen.x;
	return (nln);
}
