/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 11:25:38 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 18:32:41 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		quote_mode(void)
{
	char	*temp;

	temp = tgetstr("do", NULL);
	tputs(temp, 1, my_putchar);
	if (T_QUOTE)
		new_prompt("quote> ");
	else if (T_DQUOTE)
		new_prompt("dquote> ");
	get_cursor_first_position();
}
