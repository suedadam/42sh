/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:45:49 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/15 14:05:35 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_editing.h"
#include "ft_proto.h"

void			yank(char *buffer)
{
	int		i;

	i = 0;
	while (buffer && buffer[i])
	{
		if (regular_text(buffer[i]) == EXIT_FAILURE)
			return ;

		i++;
	}
}
