/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_visibility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:30:55 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/03 17:27:14 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		invisible_cursor(void)
{
	char	*temp;

	temp = tgetstr("mk", 0);
	tputs(temp, 1, my_putchar);
}

void		visible_cursor(void)
{
	char	*temp;

	temp = tgetstr("mk", 0);
	tputs(temp, 1, my_putchar);
}
