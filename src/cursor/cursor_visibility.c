/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_visibility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:30:55 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/09 13:21:06 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cursor.h"
#include "ft_proto.h"

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
