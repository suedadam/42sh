/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:15:12 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/09 13:38:04 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_escape.h"

static int	ft_jumps(char *temp)
{
	if (temp[1] == 'A')
		jump_prev_line(&g_shell_env.cursor);
	else if (temp[1] == 'B')
		jump_next_line(&g_shell_env.cursor);
	else if (temp[1] == 'D')
		jump_prev_word(&g_shell_env.cursor);
	else if (temp[1] == 'C')
		jump_next_word(&g_shell_env.cursor);
	return (EXIT_SUCCESS);
}

int		ft_alt(__attribute__((unused)) char byte)
{
	char	temp[3];

	T_DBLESC = 0;
	if (read(STDIN_FILENO, temp, 3) < 0)
		return (EXIT_FAILURE);
	temp[2] = '\0';
	if (temp[0] == '[')
		return (ft_jumps(temp));
	return (EXIT_SUCCESS);
}
