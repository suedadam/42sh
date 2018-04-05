/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:55:59 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 11:56:16 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		reset_prompt(void)
{
	char	*temp;

	temp = tgetstr("do", 0);
	tputs(temp, 1, my_putchar);
	new_prompt(0);
	get_cursor_first_position();
}
