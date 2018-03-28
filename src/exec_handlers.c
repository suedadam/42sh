/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 09:47:11 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/28 16:43:34 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static void		ft_idonothing(int signal)
{
	signal = 0;
	ft_printf("I do nothing amd i am ft_idonothing\n");
	return ;
}

static void		ft_window(int signal)
{

	ft_printf("I do nothing amd I am ft_window\n");
	return ;
	signal = 0;
}

void			handle_sign(int signal)
{
	char *str;

	ft_printf("coucou\n");
	if (signal != SIGQUIT)
		ft_printf("hey\n");
	if ((str = tgetstr("ve", NULL)) == NULL)
		return ;
	tputs(str, 1, my_stupidput);
	ft_printf("I have pushed escape key\n");
	exit(1);
}


int		shsignal_handlers(void)
{
	signal(SIGINT, &ft_clearline);
	signal(SIGTSTP, ft_idonothing);
	signal(SIGCONT, ft_idonothing);
	signal(SIGWINCH, ft_window);
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
	anti->antishell->c_lflag &= ~(ICANON);
	anti->antishell->c_lflag &= ~(ECHO);
	// anti->antishell->c_lflag ^= (ECHO | ICANON);
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
