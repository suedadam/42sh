/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:37:34 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/04 17:29:38 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		ft_jumpwords(char byte)
{
	if (byte == 'A')
		move_prev_line(&g_shell_env.cursor);
	else if (byte == 'B')
		move_next_line(&g_shell_env.cursor);
	else if (byte == 'D')
		move_prev_word(&g_shell_env.cursor);
	else if (byte == 'C')
		move_next_word(&g_shell_env.cursor);
	return (EXIT_SUCCESS);
}

int		ft_shift(char byte)
{
	char	temp[3];

	byte = 0;
	read(STDIN_FILENO, &temp, 3);
	if (temp[1] == 2)
		;
	else if (temp[1] == '6' && temp[2] >= 'A' && temp[2] <= 'D')
		ft_jumpwords(temp[2]);
	return (EXIT_SUCCESS);
}
