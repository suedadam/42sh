/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:25:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/30 17:11:16 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static void ft_idonothing(int lol)
{
	lol = 0;
}

int		shsignal_handlers(void)
{
	signal(SIGINT, &control_c);
	signal(SIGTSTP, ft_idonothing);
	signal(SIGCONT, ft_idonothing);
	signal(SIGWINCH, ft_idonothing);
	return (EXIT_SUCCESS);
}
