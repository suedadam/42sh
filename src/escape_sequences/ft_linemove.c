/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linemove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:44:17 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 11:08:02 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_escape.h"

int		ft_linemove(char byte)
{
	if (byte == 'D')
		cursor_to_left(&g_shell_env.cursor);
	else if (byte == 'C')
		cursor_to_right(&g_shell_env.cursor);
	else if (byte == 'H')
		cursor_to_home(&g_shell_env.cursor);
	else if (byte == 'F')
		cursor_to_end(&g_shell_env.cursor);
	return (EXIT_SUCCESS);
}
