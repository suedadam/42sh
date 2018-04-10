/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 11:25:38 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/09 16:34:10 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linefeed.h"
#include "ft_proto.h"

int		quote_mode(void)
{
	static char	*cache;

	if (!cache)
		cache = tgetstr("do", NULL);
	tputs(cache, 1, my_putchar);
	if (T_QUOTE)
	{
		if (new_prompt("quote> ") == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (T_DQUOTE)
	{
		if (new_prompt("dquote> ") == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	get_cursor_first_position();
	return (EXIT_SUCCESS);
}
