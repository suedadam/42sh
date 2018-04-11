/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:45:51 by sgardner          #+#    #+#             */
/*   Updated: 2018/04/10 18:06:59 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_memmgr.h"
#include "get_next_line.h"
#include "history.h"

static void		hist_truncate(char *path, t_mchain *mchain, t_hist *hist)
{
	t_mlink		*mlink;
	int			fd;

	if (HISTFILESIZE)
	{
		while (mchain->link_count > HISTFILESIZE)
		{
			if (mchain->link_count > hist->maxsize)
				ft_mlpop(mchain);
			else
				ft_mlremove(mchain->start);
		}
	}
	if ((fd = open(path, O_WRONLY | O_TRUNC | O_CREAT, 0600)) < 0)
		return (HDEF_ERROR(NONFATAL));
	mlink = mchain->start;
	while (mlink)
	{
		((char *)mlink->ptr)[mlink->size] = '\n';
		write(fd, mlink->ptr, mlink->size + 1);
		((char *)mlink->ptr)[mlink->size] = '\0';
		mlink = mlink->next;
	}
	if (close(fd) < 0)
		HDEF_ERROR(NONFATAL);
}

static t_bool	hist_read(char *path, t_mchain *mchain)
{
	char		*line;
	int			res;
	int			fd;

	if ((fd = open(path, O_RDONLY | O_CREAT, 0600)) < 0)
	{
		HDEF_ERROR(NONFATAL);
		return (FALSE);
	}
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (!ft_mlappend(mchain, line, ft_strlen(line)))
			HDEF_ERROR(FATAL);
	}
	if (res < 0)
	{
		close(fd);
		ft_mcdel(mchain);
		HDEF_ERROR(NONFATAL);
		return (FALSE);
	}
	if (close(fd) < 0)
		HDEF_ERROR(NONFATAL);
	return (TRUE);
}

void			hist_load(char *path, t_hist *hist)
{
	t_mchain	*mchain;
	t_mlink		*mlink;
	t_bool		truncate;

	if (!(mchain = ft_mcget("histfile")))
		HDEF_ERROR(FATAL);
	if (!hist_read(path, mchain))
		return ;
	mchain = ft_mcget("histfile");
	if (HISTFILESIZE && mchain->link_count > HISTFILESIZE)
		hist_truncate(path, mchain, hist);
	while (mchain->link_count > hist->maxsize)
		ft_mlpop(mchain);
	mlink = mchain->start;
	while (mlink)
	{
		hist_add(mlink->ptr, mlink->size)->saved = TRUE;
		mlink = ft_mlremove(mlink);
	}
}

void			hist_print(int fd, int start, int len, t_bool rev)
{
	t_hist	*hist;
	t_log	*log;
	char	*pre;
	char	*pos;
	int		n;

	hist = hist_getall();
	pre = hist_get_prefix(hist, start + len);
	while (len--)
	{
		log = hist_get(start);
		n = (rev) ? start-- + 1 : start++ + 1;
		pos = ft_strrchr(pre, '\0') - 3;
		while (n)
		{
			*pos-- = (n % 10) + '0';
			n /= 10;
		}
		while (pos != pre - 1)
			*pos-- = ' ';
		write(fd, pre, ft_strlen(pre));
		log->data[log->len] = '\n';
		write(fd, log->data, log->len + 1);
		log->data[log->len] = '\0';
	}
}

void			hist_save(char *path, t_hist *hist, int lines, t_bool append)
{
	t_mchain	*mchain;
	t_mlink		*mlink;
	t_log		*log;
	int			max;
	int			i;

	if (!(mchain = ft_mcget("histfile")))
		HDEF_ERROR(FATAL);
	if (append && !hist_read(path, mchain))
		return ;
	i = (lines && lines < hist->len) ? hist->len - lines : 0;
	while (i < hist->len)
	{
		if (!(log = hist_get(i++))->saved || !append)
		{
			ft_mlappend(mchain, log->data, log->len);
			log->saved = TRUE;
		}
	}
	hist_truncate(path, mchain, hist);
	mlink = mchain->start;
	while (mlink)
		mlink = ft_mlremove(mlink);
}
