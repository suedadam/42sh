/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:25:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/03 19:26:31 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		shsignal_handlers(void)
{
	signal(SIGINT, &control_c);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGCONT, SIG_IGN);
	signal(SIGWINCH, &window_resize);
	return (EXIT_SUCCESS);
}
