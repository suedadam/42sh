/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 11:25:38 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/04 18:39:53 by nkouris          ###   ########.fr       */
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
		new_prompt("quote> ");
		// ft_printf("quote> ");
	else if (T_DQUOTE)
		new_prompt("dquote> ");
		// ft_printf("dquote> ");
	get_cursor_first_position();
}
