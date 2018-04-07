/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:56:33 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 21:31:07 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		back_prompt(void)
{
	static char	*cache = NULL;

	if (!cache)
		cache = tgetstr("do", NULL);
	tputs(cache, 1, my_putchar);
	if (new_prompt("> ") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	get_cursor_first_position();
	return (EXIT_SUCCESS);
}
