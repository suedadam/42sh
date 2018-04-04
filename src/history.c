/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 10:56:52 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/30 18:09:42 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			add_buff_to_history(char *buffer)
{
	int		fd;

	if ((fd = open(".42sh_history", O_WRONLY | O_CREAT)) < 0
		|| lseek(fd, 1, SEEK_END) < 0)
		return (EXIT_FAILURE);
	ft_putendl_fd(buffer, fd);
	if (close(fd) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			get_history()
{
	return (EXIT_SUCCESS);
}