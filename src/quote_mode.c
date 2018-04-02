/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 11:25:38 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/02 12:06:59 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		quote_mode(char byte)
{
	char	*temp;

	byte = 0;
	temp = tgetstr("do", 0);
	tputs(temp, 1, my_putchar);
	if (T_QUOTE)
		ft_printf("quote> ");
	else if (T_DQUOTE)
		ft_printf("dquote> ");
	get_cursor_first_position();
}
