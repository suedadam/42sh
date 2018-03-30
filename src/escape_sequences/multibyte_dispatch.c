/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibyte_dispatch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:26:22 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/30 10:48:33 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		multibyte_read(char byte)
{
	if ((byte == 70 || byte <= 72) || (byte == 'C' || byte == 'D'))
		return (CURSOR_MOVE);
	else if (byte == 51)
		return (DEL_KEY);
	else if (byte == 53 || byte == 54)
		return (SCROLL);
	else if (byte == 'A' && byte == 'B')
		return (HISTORY);
	else if (byte == 1)
		return (SHIFT);
	return (EXIT_FAILURE);
}

int		cntrl_read(char byte)
{
	if (byte == 3)
		return (C_C);
	else if (byte == 7)
		return (C_G);
	else if (byte == 8)
		return (C_H);
	else if (byte == 10)
		return (C_J);
	else if (byte == 13)
		return (C_M);
	else if (byte == 15)
		return (C_O);
	else if (byte == 22)
		return (C_V);
	else if (byte == 23)
		return (C_W);
	return (-1);
}
