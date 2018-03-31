/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:38:16 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/30 17:47:00 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		control_a(void)
{
	cursor_to_home(&g_shell_env.cursor);
	return (EXIT_SUCCESS);
}
