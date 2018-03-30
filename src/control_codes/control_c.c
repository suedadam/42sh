/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:00:39 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/30 10:48:31 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void	*control_c(int c)
{
	char	*temp;
	
	c = 0;
	temp = tgetstr("cl", 0);
	tputs(temp, 1, my_putchar);
	new_prompt();
	get_cursor_first_position();
	return (EXIT_SUCCESS);
}
