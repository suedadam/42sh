/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_dispatch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:57:37 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 14:20:54 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		control_dispatch(char byte)
{
	if (byte == 1)
		return (C_A);
	else if (byte == 5)
		return (C_E);
	else if (byte == 7)
		return (C_G);
	else if (byte == 8 || byte == 127)
		return (C_H);
	else if (byte == 10)
		return (C_J);
	else if (byte == 11)
		return (C_K);
	else if (byte == 12)
		return (C_L);
	else if (byte == 13)
		return (C_M);
	else if (byte == 15)
		return (C_O);
	else if (byte == 21)
		return (C_U);
	else if (byte == 22)
		return (C_V);
	else if (byte == 23)
		return (C_W);
	else if (byte == 25)
	{
		ft_printf("go");
		return (C_Y);
	}
	ft_printf("fail");
	return (-1);
}
