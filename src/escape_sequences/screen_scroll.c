/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_scroll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:59:34 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/09 13:48:26 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_escape.h"

int		scroll_up(void)
{
	static char	*cache = NULL;

	//cursor_to_left_margin();
	if (!cache)
		cache = tgetstr("sf", 0);
	tputs(cache, 1, my_putchar);
	return (EXIT_SUCCESS);
}

int		scroll_down(void)
{
	static char	*cache = NULL;

	//cursor_to_left_margin();
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
