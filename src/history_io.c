/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:45:51 by sgardner          #+#    #+#             */
/*   Updated: 2018/04/08 04:43:44 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "history.h"

static void	hist_truncate(char *path)
{
	char	*line;
	int		fd;
	int		count;
	off_t	total;
	int		res;

	if ((fd = open(path, O_RDWR, 0600)) < 0)
		return (DEFAULT_ERROR(NONFATAL));
	count = 0;
	total = 0;
	while ((res = get_next_line(fd, &line)) > 0)
	{
		total += ft_strlen(line) + 1;
		free(line);
		if (++count == HISTFILESIZE)
			break ;
	}
	if (res < 0)
		DEFAULT_ERROR(NONFATAL);
	if (!res && count == HISTFILESIZE && ftruncate(fd, total) < 0)
		DEFAULT_ERROR(NONFATAL);
	if (close(fd) < 0)
		DEFAULT_ERROR(NONFATAL);
}

void		hist_load(char *path, t_hist *hist)
{
	char	*line;
	int		fd;
	int		res;

	if (!path)
		return ;
	if ((fd = open(path, O_RDONLY | O_CREAT, 0600)) < 0)
		return (DEFAULT_ERROR(NONFATAL));
	while ((res = get_next_line(fd, &line)) > 0)
		hist_add(line, ft_strlen(line))->saved = TRUE;
	if (res < 0)
	{
		close(fd);
		return (DEFAULT_ERROR(NONFATAL));
	}
	if (close(fd) < 0)
		DEFAULT_ERROR(NONFATAL);
	if (HISTFILESIZE > 0
		&& hist->len > HISTFILESIZE
		&& !ft_strcmp(path, HISTFILE))
	{
		hist_save(path, hist, HISTFILESIZE, FALSE);
		hist_truncate(path);
	}
}

static void	write_endl(int fd, char *data, size_t len)
{
	data[len] = '\n';
	write(fd, data, len + 1);
	data[len] = '\0';
}

void		hist_print(int start, int len)
{
	t_hist	*hist;
	t_log	*log;
	char	*pre;
	char	*pos;
	int		n;

	if (!len)
		return ;
	hist = hist_getall();
	pre = hist_get_prefix(hist, start + len);
	while (len)
	{
		n = start + 1;
		pos = ft_strrchr(pre, '\0') - 3;
		while (n)
		{
			*pos-- = (n % 10) + '0';
			n /= 10;
		}
		log = hist_get(start++);
		write(STDOUT_FILENO, pre, ft_strlen(pre));
		write_endl(STDOUT_FILENO, log->data, ft_strlen(log->data));
		--len;
	}
}

void		hist_save(char *path, t_hist *hist, int lines, t_bool append)
{
	t_log	*log;
	int		fd;
	int		flags;
	int		max;
	int		i;

	if (!path)
		return ;
	flags = O_WRONLY | O_CREAT | ((append) ? O_APPEND : O_TRUNC);
	if ((fd = open(path, flags, 0600)) < 0)
		return (DEFAULT_ERROR(NONFATAL));
	i = (lines && lines < hist->len) ? hist->len - lines : 0;
	max = (HISTFILESIZE) ? HISTFILESIZE : hist->len;
	while (i < hist->len && i < max)
	{
		if (!(log = hist_get(i++))->saved || !append)
			write_endl(fd, log->data, log->len);
	}
	if (close(fd) < 0)
		DEFAULT_ERROR(NONFATAL);
	if (append)
		hist_truncate(path);
}
