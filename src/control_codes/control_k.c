/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_k.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:02:09 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 20:05:02 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		control_k(void)
{
	if (g_shell_env.cursor.position != g_shell_env.buffer->length)
		cut_line_after_cursor();
	return (EXIT_SUCCESS);
}
