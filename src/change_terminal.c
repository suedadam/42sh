/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_terminal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:21:04 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 20:53:06 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		ft_setty(void)
{
	g_shell_env.shell_tty->c_lflag ^= (ECHO | ICANON);
	if ((tcsetattr(STDIN_FILENO, TCSAFLUSH, g_shell_env.shell_tty)) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		ft_restoretty(void)
{
	if ((tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_shell_env.original_tty)) < 0)
	{
		g_ft_errnum = SYSERR;
		return (EXIT_FAILURE);
	}
	ft_printf("exit\n");
	return (EXIT_SUCCESS);
}
