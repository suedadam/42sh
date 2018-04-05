/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:15:12 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/04 18:39:50 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		ft_alt(char byte)
{
	char	temp[2];

	T_DBLESC = 0;
	read(STDIN_FILENO, temp, 2);
	if (temp[1] == 'A')
		move_prev_line(&g_shell_env.cursor);
	else if (temp[1] == 'B')
		move_next_line(&g_shell_env.cursor);
	else if (temp[1] == 'D')
		move_prev_word(&g_shell_env.cursor);
	else if (temp[1] == 'C')
		move_next_word(&g_shell_env.cursor);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
