/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:07:54 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 15:22:50 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		get_window_size(void)
{
	if ((ioctl(0, TIOCGWINSZ, &g_shell_env.window)) < 0)
	{
		g_ft_errnum = SYSERR;
		return (EXIT_FAILURE);
	}
	g_shell_env.cursor.og_screen.x = g_shell_env.window.ws_col;
	g_shell_env.cursor.og_screen.y = g_shell_env.window.ws_row;
	return (EXIT_SUCCESS);
}
