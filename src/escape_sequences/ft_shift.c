/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:37:34 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 11:44:22 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		ft_shift(char byte)
{
	char	temp[3];
    
//	ft_printf("byte : <%d>\n", byte);
	byte = 0;
	read(STDIN_FILENO, &temp, 3);
//	ft_printf("next 3 : <%d, %d, %d>\n", temp[0], temp[1], temp[2]);
	if (temp[1] == '2' && temp[2] >= 'A' && temp[2] <= 'D')
		ft_linemove(temp[2]);
	else if (temp[1] == '6' && temp[2] >= 'A' && temp[2] <= 'D')
		ft_linemove(temp[2]);
	return (EXIT_SUCCESS);
}
