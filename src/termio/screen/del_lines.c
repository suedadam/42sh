/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:04:16 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 12:04:37 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_screen.h"
#include "ft_proto.h"

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
