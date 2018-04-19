/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:45:49 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/18 20:50:15 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_editing.h"
#include "ft_proto.h"

void			yank(char *buffer)
{
	int		i;
	int		corr;

	i = 0;
	corr = 0;
	while (buffer && buffer[i])
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = ' ';
			corr = 1;
		}
		if (regular_text(buffer[i]) == EXIT_FAILURE)
			return ;
		if (corr == 1)
		{
			ft_backspace();
			corr = 0;
		}
		i++;
	}
	verify_hanging();
}
