/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrn_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:02:56 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/29 16:36:45 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		screen_size(&anti)
{
	if (ioclt(STDIN_FILENO, TIOCGWINSZ) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
