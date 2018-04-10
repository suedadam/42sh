/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paren_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:33:08 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 15:51:02 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hangingbyte.h"
#include "ft_proto.h"

void	paren_check(char byte)
{
	if (byte == '(' && !(T_QUOTE | T_DQUOTE))
		T_OPAREN++;
	else if (byte == ')' && T_OPAREN)
	{
		T_OPAREN--;
		T_CPAREN = (T_OPAREN == 0) ? 1 : 0;
	}
}
