/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 22:00:11 by sgardner          #+#    #+#             */
/*   Updated: 2018/04/09 20:57:09 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "history.h"

t_log	*hist_add(char *raw, int len)
{
	t_hist	*hist;
	t_log	*log;

	hist = hist_getall();
	if (hist->size < hist->maxsize && hist->len == hist->size)
	{
		if (hist->size * 2 > hist->maxsize)
			hist_resize(hist, hist->maxsize);
		else
			hist_resize(hist, hist->size * 2);
	}
	if (hist->len > 0)
		hist->tail = HPOS(hist->tail, 1, hist->size);
	log = &hist->arr[hist->tail];
	if (log->data)
	{
		free(log->data);
		hist->head = HPOS(hist->head, 1, hist->size);
	}
	log->data = raw;
	log->len = len;
	log->saved = FALSE;
	if (hist->len < hist->size)
		++hist->len;
	return (log);
}

void	hist_clear(void)
{
	t_hist	*hist;
	t_bool	resize;
	int		nsize;
	int		i;

	hist = hist_getall();
	nsize = (hist->maxsize < GROWTH_PAD) ? hist->maxsize : GROWTH_PAD;
	resize = (hist->size > nsize);
	while (hist->len)
	{
		i = HPOS(hist->head, --hist->len, hist->size);
		free(hist->arr[i].data);
		if (!resize)
			ft_memset(&hist->arr[i], 0, sizeof(t_log));
	}
	if (resize)
	{
		free(hist->arr);
		if (!(hist->arr = ft_memalloc(sizeof(t_log) * nsize)))
			DEFAULT_ERROR(FATAL);
		hist->size = nsize;
	}
	hist->head = 0;
	hist->tail = 0;
}

t_bool	hist_delete(int offset)
{
	t_hist	*hist;
	int		forward;

	hist = hist_getall();
	if (offset < 0 || offset >= hist->len)
		return (FALSE);
	offset = HPOS(hist->head, offset, hist->size);
	free(hist->arr[offset].data);
	ft_memset(&hist->arr[offset], 0, sizeof(t_log));
	if (hist->head == offset)
		hist->head = HPOS(hist->head, 1, hist->size);
	else
	{
		while ((forward = HPOS(offset, 1, hist->size)) != hist->head)
		{
			hist->arr[offset] = hist->arr[forward];
			offset = forward;
		}
	}
	hist->tail = HPOS(hist->head, --hist->len - 1, hist->size);
	return (TRUE);
}

t_log	*hist_get(int offset)
{
	t_hist	*hist;

	hist = hist_getall();
	if (offset < 0 || offset >= hist->len)
		return (NULL);
	return (&hist->arr[HPOS(hist->head, offset, hist->size)]);
}

t_hist	*hist_getall(void)
{
	static t_hist	hist;
	int				size;

	if (!(hist.maxsize = HISTSIZE))
		hist.maxsize = 500;
	if (!hist.arr)
	{
		size = (hist.maxsize < GROWTH_PAD) ? hist.maxsize : GROWTH_PAD;
		if (!(hist.arr = ft_memalloc(sizeof(t_log) * size)))
			DEFAULT_ERROR(FATAL);
		hist.size = size;
		if (HISTFILE)
			hist_load(HISTFILE, &hist);
	}
	return (hist_scale(&hist));
}
