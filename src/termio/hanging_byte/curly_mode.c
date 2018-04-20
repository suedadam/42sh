/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curly_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:47:44 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/16 02:43:16 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hangingbyte.h"
#include "ft_proto.h"

void	curly_check(char byte)
{
	if (byte == '{' && !(T_QUOTE | T_DQUOTE))
		T_OCURLY++;
	else if (byte == '}' && T_OCURLY)
	{
		T_OCURLY--;
		T_CCURLY = (T_OCURLY == 0) ? 1 : 0;
	}
}

int		curly_delete(char byte)
{
	if (byte == '}')
	{
		if (T_CCURLY)
		{
			T_CCURLY = 0;
			T_OCURLY++;
		}
		else if (T_OCURLY)
			T_OCURLY++;
		return (EXIT_SUCCESS);
	}
	else if (byte == '(')
	{
		T_OCURLY ? T_OCURLY-- : 0;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
