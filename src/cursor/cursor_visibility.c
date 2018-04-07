/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_visibility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:30:55 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 19:52:42 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		invisible_cursor(void)
{
	static char	*cache = NULL;

	if (!cache)
		cache = tgetstr("vi", 0);
	tputs(cache, 1, my_putchar);
}

void		visible_cursor(void)
{
	static char	*cache = NULL;

	if (!cache)
		cache = tgetstr("ve", 0);
	tputs(cache, 1, my_putchar);
}
