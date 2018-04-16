/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paren_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:33:08 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/16 06:41:46 by nkouris          ###   ########.fr       */
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

int		paren_delete(char byte)
{
	if (byte == ')')
	{
		if (T_CPAREN)
		{
			T_CPAREN = 0;
			T_OPAREN++;
		}
		else if (T_OPAREN)
			T_OPAREN++;
		return (EXIT_SUCCESS);
	}
	else if (byte == '(')
	{
		T_OPAREN ? T_OPAREN-- : 0;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
