/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:15:12 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 13:51:12 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

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
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_edit(char byte)
{
	if (byte == 'w')
		cut_word_before_cursor();
	else if (byte == 'k')
		cut_line_after_cursor();
	else if (byte == 'u')
		cut_line_before_cursor();
	else if (byte == 'y')
		ft_printf(" OH YEAH");
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		ft_alt(char byte)
{
	char	temp[3];
	int		ret;

	T_DBLESC = 0;
	read(STDIN_FILENO, temp, 3);
	temp[2] = 0;
	if (temp[0] == '[')
		ret = ft_jumps(temp);
	else
		ret = ft_edit(byte);
	return (ret);
}
