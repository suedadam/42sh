/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:25:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 11:25:06 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		_y(int c)
{
	c = 0;
	yank(g_shell_env.paperweight.buff);
}

int		shsignal_handlers(void)
{
	signal(SIGINT, &control_c);
	signal(SIGTSTP, &_y);
	signal(SIGCONT, SIG_IGN);
	signal(SIGWINCH, &window_resize);
	return (EXIT_SUCCESS);
}
