/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:58:23 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/30 14:29:33 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		control_l(char byte)
{
	char	*temp;
	
	temp = tgetstr("cl", 0);
	tputs(temp, 1, my_putchar);
	new_prompt();
	reprint_buffer();
	move_cursor(&g_shell_env.cursor);
	return (EXIT_SUCCESS);
}
