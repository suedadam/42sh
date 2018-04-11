/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:53:50 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/03 17:27:11 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maincontrol.h"
#include "ft_proto.h"

/*
** putchar is supposed to return the value that is written or an EOF on error.
*/

int		my_putchar(int chrr)
{
	return (write(1, &chrr, 1) ? chrr : EOF);
}
