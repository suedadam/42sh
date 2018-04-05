/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:58:23 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 12:22:31 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		control_l(void)
{
	char	*temp;

	temp = tgetstr("cl", 0);
	tputs(temp, 1, my_putchar);
	new_prompt(0);
	reprint_buffer();
	move_cursor(&g_shell_env.cursor);
	return (EXIT_SUCCESS);
}
