/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 09:47:11 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/23 11:05:42 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void	func(int clr)
{
	clr = 0;
	ft_printf("clearline\n");
}

int		shsignal_handlers(void)
{
	signal(SIGINT, &func);
	return (EXIT_SUCCESS);
}

int		ft_setty(t_terminf *anti)
{
	anti->antishell->c_lflag ^= (ECHO | ICANON);
	if ((tcsetattr(STDIN_FILENO, TCSAFLUSH, anti->antishell)) < 0)
	{
		ft_printf("other fail\n");
		g_ft_errnum = SYSERR;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int		ft_resetty(t_terminf *anti)
{
	anti->antishell->c_lflag ^= (ECHO | ICANON);
	if ((tcsetattr(STDIN_FILENO, TCSAFLUSH, anti->antishell)) < 0)
	{
		ft_printf("other fail\n");
		g_ft_errnum = SYSERR;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int		ft_restoretty(t_terminf *anti)
{
	if ((tcsetattr(STDIN_FILENO, TCSAFLUSH, &anti->og)) < 0)
	{
		g_ft_errnum = SYSERR;
		return (EXIT_FAILURE);
	}
	printf("restore\n");
	return (EXIT_SUCCESS);
}

