/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibyte_dispatch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:26:22 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 11:08:02 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_escape.h"
#include "ft_proto.h"

inline __attribute__((always_inline)) int	multibyte_dispatch(char byte)
{
	if (ARROWS_LEFTRIGHT(byte) || HOME_END_KEY(byte))
		return (CURSOR_MOVE);
	else if (DELETE_KEY(byte))
		return (DEL_KEY);
	else if (SHIFTMOD(byte))
		return (SHIFT);
	else if (T_DBLESC)
		return (ALT);
	else if (PGKEYS(byte))
		return (SCROLL);
	else if (ARROWS_UPDOWN(byte))
		return (HISTORY);
	return (-1);
}
