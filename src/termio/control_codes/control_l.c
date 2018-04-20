/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:58:23 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/15 16:19:36 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_control.h"
#include "ft_proto.h"

int		control_l(void)
{
	static char	*cache = NULL;
	size_t		og_curpos;

	og_curpos = g_shell_env.cursor.position;
	if (!cache)
		cache = tgetstr("cl", 0);
	tputs(cache, 1, my_putchar);
	if (new_prompt(0) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	g_shell_env.cursor.position = og_curpos;
	return (reprint_buffer());
}
