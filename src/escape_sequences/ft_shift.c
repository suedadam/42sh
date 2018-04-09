/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:37:34 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 22:16:15 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_escape.h"

int		ft_shift(__attribute__((unused)) char byte)
{
	char	temp[3];

	if (read(STDIN_FILENO, &temp, 3) < 0)
		return (EXIT_FAILURE);
	if (temp[1] == '2' && temp[2] >= 'A' && temp[2] <= 'D')
		ft_linemove(temp[2]);
	else if (temp[1] == '6' && temp[2] >= 'A' && temp[2] <= 'D')
		ft_linemove(temp[2]);
	return (EXIT_SUCCESS);
}
