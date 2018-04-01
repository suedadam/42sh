/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrn_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:02:56 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/31 18:46:50 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		get_window_size(void)
{
	ioctl(0, TIOCGWINSZ, &g_shell_env.window);
	// if (ioclt(STDIN_FILENO, TIOCGWINSZ) < 0)
		// return (EXIT_FAILURE);
		// ft_printf("window size : %d,%d\n", g_shell_env.window.ws_col, g_shell_env.window.ws_row);
	return (EXIT_SUCCESS);
}
