/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_terminal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:21:04 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/29 14:25:05 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		ft_setty(t_terminf *shell_env)
{
	shell_env->shell_tty->c_lflag ^= (ECHO | ICANON);
	if ((tcsetattr(STDIN_FILENO, TCSAFLUSH, shell_env->shell_tty)) < 0)
	{
		ft_printf("other fail\n");
		g_ft_errnum = SYSERR;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int		ft_restoretty(t_terminf *shell_env)
{
	if ((tcsetattr(STDIN_FILENO, TCSAFLUSH, &shell_env->original_tty)) < 0)
	{
		g_ft_errnum = SYSERR;
		return (EXIT_FAILURE);
	}
	ft_printf("exit\n");
	return (EXIT_SUCCESS);
}
