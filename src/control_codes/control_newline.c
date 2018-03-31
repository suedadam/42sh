/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_newline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:27:44 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/30 17:25:03 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		control_newline(char byte)
{
	int		c;

	c = 0;
	byte = 0;
	control_c(c);
	return (EXIT_SUCCESS);
}
