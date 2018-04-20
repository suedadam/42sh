/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:40:34 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 20:05:14 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_control.h"
#include "ft_proto.h"

int		control_u(void)
{
	if (g_shell_env.cursor.position)
		cut_line_before_cursor();
	return (EXIT_SUCCESS);
}
