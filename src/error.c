/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 09:51:52 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/25 19:16:15 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

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
=======
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 22:01:40 by sgardner          #+#    #+#             */
/*   Updated: 2018/03/25 00:33:30 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "error.h"

void	default_error(void)
{
	FATAL_ERROR(sys_errlist[errno]);
}

void	fatal_error(const char *msg)
{
	sh_error(g_pname, msg, NULL);
	exit(1);
}

void	sh_error(const char *prefix, const char *err, const char *param)
{
	if (prefix)
	{
		ft_putstr_fd(prefix, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(err, 2);
	if (param)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(param, 2);
	}
	write(2, "\n", 1);
}
>>>>>>> origin
