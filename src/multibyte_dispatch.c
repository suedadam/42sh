/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibyte_dispatch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:26:22 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/25 19:16:27 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		line_seek(t_terminf *anti, char byte)
{
	if (byte == 'C')
		ft_curight(anti);
	else if (byte == 'D')
		ft_curleft(anti);
	else if (byte == 72)
		ft_curhome(anti);
	return (EXIT_SUCCESS);
}
