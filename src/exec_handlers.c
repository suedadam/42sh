/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 09:47:11 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/28 16:20:44 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void			handle_sign(int signal)
{
	char *str;

	if ((str = tgetstr("ve", NULL)) == NULL)
		return ;
	tputs(str, 1, my_putchar);
	if (tcsetattr(0, TCSADRAIN, &g_terence.oldterm) == -1)
		return ;
	exit(1);
}


int		shsignal_handlers(void)
{
	signal(SIGINT, &ft_clearline);
	signal(SIGQUIT, handle_quit;
	// signal(SIGTSTP, );
	// signal(SIGCONT, );
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
	ft_printf("exit\n");
	return (EXIT_SUCCESS);
}
