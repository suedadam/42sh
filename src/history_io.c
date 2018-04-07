/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:45:51 by sgardner          #+#    #+#             */
/*   Updated: 2018/04/06 23:05:35 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "history.h"

void		hist_load(char *path, t_hist *hist)
{
	int	fd;

	UNUSED(hist);
	if (!path)
		return ;
	if ((fd = open(path, O_RDONLY | O_CREAT)) < 0)
		return (DEFAULT_ERROR(NONFATAL));
	close(fd);
}

void		hist_save(char *path, t_hist *hist, int lines, t_bool force)
{
	UNUSED(path);
	UNUSED(hist);
	UNUSED(lines);
	UNUSED(force);
}

static void	hist_truncate(char *path, t_hist *hist)
{
	UNUSED(path);
	UNUSED(hist);
}
