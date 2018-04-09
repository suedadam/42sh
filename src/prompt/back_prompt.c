/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:56:33 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/07 18:21:29 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int		back_prompt(void)
{
	static char *cache = NULL;

	if (!cache)
		cache = tgetstr("do", NULL);
	tputs(cache, 1, my_putchar);
	if (new_prompt("> ") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	get_cursor_first_position();
	return (EXIT_SUCCESS);
}
