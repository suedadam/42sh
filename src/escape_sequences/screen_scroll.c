/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_scroll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:59:34 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 20:56:52 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"



int		scroll_up(void)
{
	char	*temp;

	temp = tgetstr("sf", 0);
	tputs(temp, 1, my_putchar);
	return (EXIT_SUCCESS);
}

int		scroll_down(void)
{
	char	*temp;

	//cursor_to_left_margin();
	temp = tgetstr("sr", 0);
	tputs(temp, 1, my_putchar);
	return (EXIT_SUCCESS);
}

int		ft_scroll(char byte)
{
	if (byte == 'A')
		scroll_up();
	else
		scroll_down();
	return (EXIT_SUCCESS);
}
