/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:58:23 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 22:52:56 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_control.h"

int		control_l(void)
{
	static char	*cache = NULL;

	if (!cache)
		cache = tgetstr("cl", 0);
	tputs(cache, 1, my_putchar);
	if (new_prompt(0) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (reprint_buffer());
}
