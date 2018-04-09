/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 09:51:52 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/25 19:16:15 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maincontrol.h"

t_errstr g_errtable[6] =
{
	{0, NULL, 0},
	{TGETN, "Terminfo database not found\n", 28},
	{TGETZ, "No such entry\n", 14},
	{TGETSTR, "tgetstr err: Not available\n", 27},
	{TERMGET, "tgetattr err: Not available\n", 27},
	{0, NULL, 0},
};

void		ft_terror(void)
{
	if (g_ft_errnum == SYSERR)
		perror(strerror(errno));
	else
		write(2, g_errtable[g_ft_errnum].str, g_errtable[g_ft_errnum].len);
}	
