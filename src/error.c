/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 22:01:40 by sgardner          #+#    #+#             */
/*   Updated: 2018/04/06 04:04:31 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "error.h"

void	default_error(t_bool fatal)
{
	const char	*msg;

	msg = sys_errlist[errno];
	if (fatal)
		fatal_error(msg);
	sh_error(g_pname, msg, NULL);
}

void	fatal_error(const char *msg)
{
	sh_error(g_pname, msg, NULL);
	write(STDERR_FILENO, "Exiting...\n", 12);
	exit(1);
}

void	sh_error(const char *prefix, const char *err, const char *param)
{
	if (prefix)
	{
		write(STDERR_FILENO, prefix, ft_strlen(prefix));
		write(STDERR_FILENO, ": ", 2);
	}
	write(STDERR_FILENO, err, ft_strlen(err));
	if (param)
	{
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, param, ft_strlen(param));
	}
	write(STDERR_FILENO, "\n", 1);
}
