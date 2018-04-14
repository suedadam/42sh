/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:02:17 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/14 16:14:32 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

int			history_append(char *buffer)
{
	int		fd;

	if (!buffer)
		return (EXIT_FAILURE);
	if ((fd = open(HISTORY_FILE, O_CREAT | O_WRONLY)) < 0)
		return (EXIT_FAILURE);
	ft_putendl_fd(buffer, fd);
	if (close(fd) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
