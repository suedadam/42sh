/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrn_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:02:56 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/25 19:16:17 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		screen_size(&anti)
{
	if (ioclt(STDIN_FILENO, TIOCGWINSZ) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
