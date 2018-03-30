/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibyte_dispatch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:26:22 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/30 11:51:13 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		multibyte_read(char byte)
{
	if (LSEEK(byte))
		return (MOVE);
	else if (DEL(byte))
		return (DEL);
	else if (SCRL(byte))
		return (SCRL);
	else if (HIST(byte))
		return (HIST);
	else if (byte == 1)
		return (SHIFT);
	return (EXIT_FAILURE);
}

