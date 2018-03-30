/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibyte_dispatch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:26:22 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/30 12:03:57 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		multibyte_dispatch(char byte)
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
