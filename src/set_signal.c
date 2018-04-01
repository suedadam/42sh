/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:25:41 by nkouris           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/30 18:09:42 by nkouris          ###   ########.fr       */
=======
/*   Updated: 2018/03/31 15:17:04 by tle-huu-         ###   ########.fr       */
>>>>>>> termio
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static void ft_idonothing(int lol)
{
<<<<<<< HEAD
	lol = 0;
}

int		shsignal_handlers(void)
{
	signal(SIGINT, &control_c);
=======
	lol = 4;
}


int		shsignal_handlers(void)
{
	// signal(SIGINT, control_c);
>>>>>>> termio
	signal(SIGTSTP, ft_idonothing);
	// signal(SIGCONT, ft_idonothing);
	// signal(SIGWINCH, ft_idonothing);
	return (EXIT_SUCCESS);
}
