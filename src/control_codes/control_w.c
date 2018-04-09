/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_w.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:37:31 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 20:05:05 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_control.h"

int		control_w(void)
{
	if (g_shell_env.cursor.position)
		cut_word_before_cursor();
	return (EXIT_SUCCESS);
}
