/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:58:23 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/03 14:26:48 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		control_l(void)
{
	char	*temp;
	
	temp = tgetstr("cl", 0);
	tputs(temp, 1, my_putchar);
	new_prompt();
	reprint_buffer();
	move_cursor(&g_shell_env.cursor);
	return (EXIT_SUCCESS);
}
