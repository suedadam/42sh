/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibyte_dispatch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:26:22 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 16:25:30 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		multibyte_dispatch(char byte)
{
	if (byte == 67 || byte == 68 || byte == 70 || byte == 72)
		return (CURSOR_MOVE);
	else if (byte == 51)
		return (DEL_KEY);
	else if (byte == 49)
		return (SHIFT);
	else if (T_DBLESC)
		return (ALT);
	else if (byte == 53 || byte == 54 )
		return (SCROLL);
	else if (byte == 65 || byte == 66)
	 	return (HISTORY);
	else if (byte == 126)
		return (PAGE);
	return (-1);
}
