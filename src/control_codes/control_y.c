/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_y.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:03:00 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 14:05:57 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_control.h"

int		control_y(void)
{
	yank(g_shell_env.paperweight.buff);
	return (EXIT_SUCCESS);
}
