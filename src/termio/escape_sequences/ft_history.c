/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:06:48 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/14 22:42:00 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_escape.h"
#include "ft_proto.h"

int		ft_history(char byte)
{
	if (byte == 'A')
		up_history_command();
	else if (byte == 'B')
		down_history_command();
	return (EXIT_SUCCESS);
}
