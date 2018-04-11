/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:56:33 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 14:30:22 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_proto.h"

int		drop_prompt(char *str)
{
	static char *cache = NULL;

	if (!cache)
		cache = tgetstr("do", NULL);
	tputs(cache, 1, my_putchar);
	if (new_prompt(str) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	get_cursor_first_position();
	return (EXIT_SUCCESS);
}
