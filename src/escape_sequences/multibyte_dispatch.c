/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibyte_dispatch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:26:22 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/04 19:35:44 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		multibyte_dispatch(char byte)
{
	if (byte == 51)
		return (DEL_KEY);
	else if ((byte == 'C' || byte == 'D' || byte == 'F' || byte == 'H'))
		return (CURSOR_MOVE);
	else if (byte == 53 || byte == 54 )
		return (SCROLL);
	// else if (byte == 'A' || byte == 'B')
	// 	return (HISTORY);
	else if (byte == '1')
		return (SHIFT);
	else if (T_DBLESC)
		return (ALT);
	return (-1);
}
