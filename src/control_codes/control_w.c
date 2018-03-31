/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_w.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:37:31 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/30 17:58:43 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		control_w(void)
{
	char	*temp;

	cursor_to_home(&g_shell_env.cursor);
	temp = tgetstr("ce", 0);
	tputs(temp, 1, &my_putchar);
	reset_buffer();
	return (EXIT_SUCCESS);
}
