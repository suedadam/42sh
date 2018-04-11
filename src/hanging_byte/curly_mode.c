/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curly_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:47:44 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 15:53:53 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_hangingbyte.h"
#include "ft_proto.h"

void	curly_check(char byte)
{
	if (byte == '{' && !(T_QUOTE | T_DQUOTE))
		T_OCURLY++;
	else if (byte == '}' && T_OPAREN)
	{
		T_OCURLY--;
		T_CCURLY = (T_OCURLY == 0) ? 1 : 0;
	}
}
