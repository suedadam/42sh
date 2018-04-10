/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_scroll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:59:34 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/09 19:32:59 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_escape.h"

int		scroll_up(void)
{
	static char	*cache = NULL;

	if (!cache)
		cache = tgetstr("sf", 0);
	tputs(cache, 1, my_putchar);
	return (EXIT_SUCCESS);
}

int		scroll_down(void)
{
	static char	*cache = NULL;

	if (!cache)
		cache = tgetstr("sr", 0);
	tputs(cache, 1, my_putchar);
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
