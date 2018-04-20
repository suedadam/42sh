/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
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
