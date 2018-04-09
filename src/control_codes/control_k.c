/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_k.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:02:09 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/07 15:41:12 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_control.h"

int		control_k(void)
{

	if (g_shell_env.cursor.position != g_shell_env.cursor.buffer_length)
		cut_line_after_cursor();
	return (EXIT_SUCCESS);
}
