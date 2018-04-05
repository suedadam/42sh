/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_scroll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:59:34 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/04 18:39:56 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		scroll_up(void)
{
	char	*temp;

	temp = tgetstr("sf", 0);
	tputs(temp, 1, my_putchar);
	return (EXIT_SUCCESS);
}

int		scroll_down(void)
{
	char	*temp;

	temp = tgetstr("sr", 0);
	tputs(temp, 1, my_putchar);
	return (EXIT_SUCCESS);
}

int		count_lines(void)
{
	int		nln;

	nln = 0;
	if (g_shell_env.buffer->length)
		nln =  (g_shell_env.buffer->length + g_shell_env.cursor.og_position.x) /
			g_shell_env.cursor.og_screen.x;
	return (nln);	
}

int		del_lines(void)
{
	char	*temp;
	int		nln;

	nln = count_lines();
	cursor_to_end(&g_shell_env.cursor);
	while (nln > 0)
	{
		temp = tgetstr("dl", 0);
		tputs(temp, 1, &my_putchar);
		temp = tgetstr("up", 0);
		tputs(temp, 1, &my_putchar);
		nln--;
	}
	cursor_to_home(&g_shell_env.cursor);
	temp = tgetstr("ce", 0);
	tputs(temp, 1, &my_putchar);
	return (EXIT_SUCCESS);
}
