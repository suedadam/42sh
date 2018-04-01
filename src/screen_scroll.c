/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_scroll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:59:34 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/31 11:05:43 by nkouris          ###   ########.fr       */
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

	temp = tgetstr("sr", 0);
	tputs(temp, 1, my_putchar);
	return (EXIT_SUCCESS);
}
