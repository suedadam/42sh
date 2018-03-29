/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:25:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/29 16:41:13 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		shsignal_handlers(void)
{
	signal(SIGINT, &ft_clearline);
	signal(SIGTSTP, ft_idonothing);
	signal(SIGCONT, ft_idonothing);
	signal(SIGWINCH, ft_window);
	return (EXIT_SUCCESS);
}
