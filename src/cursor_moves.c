/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:57:48 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/28 15:37:21 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		my_stupidput(int chrr)
{
	write(1, &chrr, 1);
	return (EXIT_SUCCESS);
}

int		ft_curight(t_terminf *anti)
{
	anti = (void *)anti;
	if (write(STDIN_FILENO, "\e[1C", 4) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		ft_curleft(t_terminf *anti)
{
	anti = (void *)anti;
	if (write(STDIN_FILENO, "\e[1D", 4) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		ft_curhome(t_terminf *anti)
{
	char	*temp;

	anti = (void *)anti;
	temp = tgetstr("cr", 0);
	tputs(temp, 1, my_stupidput);
	return (EXIT_SUCCESS);
}

int		ft_curend(t_terminf *anti)
{
	ft_printf("implement me!");
	/*
	char	*temp;

	temp = tgetstr("", 0);
	tputs(temp, 1, my_stupidput);
	*/
	anti = (void *)anti;
	return (EXIT_SUCCESS);
}

int		ft_clearscreen(t_terminf *anti)
{
	char	*temp;

	temp = tgetstr("cl", 0);
	tputs(temp, 1, my_stupidput);
	anti = (void *)anti;
	ft_printf("42sh%% ");
	return (EXIT_SUCCESS);
}

int		ft_backspace(t_terminf *anti)
{
	char	*temp;

	ft_curleft(anti);
	temp = tgetstr("dc", 0);
	tputs(temp, 1, my_stupidput);
	return (EXIT_SUCCESS);
}

void	ft_clearline(int clr)
{
	char	*temp;

	clr = 0;
	temp = tgetstr("do", 0);
	tputs(temp, 1, my_stupidput);
	ft_printf("42sh%% ");
}

int		ft_passinput(t_terminf *anti)
{
	ft_clearline(0);
	anti = (void *)anti;
	return (EXIT_SUCCESS);
}
