/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 22:00:11 by sgardner          #+#    #+#             */
/*   Updated: 2018/04/06 22:45:48 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "history.h"

void	hist_add(char *raw, int len)
{
	t_hist	*hist;
	t_log	*log;

	hist = hist_getall();
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
}

void	hist_clear(void)
{
	t_hist	*hist;
	int		i;

	i = 0;
	hist = hist_getall();
	while (i < hist->size)
		ft_memset(&hist->arr[i++], 0, sizeof(t_log));
	hist->head = 0;
	hist->tail = 0;
	hist->len = 0;
}

void	hist_delete(int offset)
{
	t_hist	*hist;
	int		forward;

	hist = hist_getall();
	if (offset < 0 || offset >= hist->len)
		return (hist_error(ERR_HIST_OOR, &offset, TRUE));
	offset = HPOS(hist->head, offset, hist->size);
	free(hist->arr[offset].data);
	ft_memset(&hist->arr[offset], 0, sizeof(t_log));
	if (hist->head == offset)
		hist->head = HPOS(hist->head, 1, hist->size);
	else if (hist->len > 1)
	{
		while ((forward = HPOS(offset, 1, hist->size)) != hist->head)
		{
			hist->arr[offset] = hist->arr[forward];
			offset = forward;
		}
	}
	hist->tail = HPOS(hist->head, --hist->len - 1, hist->size);
}

char	*hist_get(int offset)
{
	t_hist	*hist;

	hist = hist_getall();
	if (offset < 0 || offset >= hist->len)
	{
		hist_error(ERR_HIST_OOR, &offset, TRUE);
		return (NULL);
	}
	offset = HPOS(hist->head, offset, hist->size);
	return (hist->arr[offset].data);
}

t_hist	*hist_getall(void)
{
	static t_hist	hist;
	int				hsize;

	if (!(hsize = HISTSIZE))
		hsize = 500;
	if (!hist.arr)
	{
		if (!(hist.arr = ft_memalloc(sizeof(t_log) * hsize)))
			DEFAULT_ERROR(FATAL);
		hist.size = hsize;
		hist_load(HISTFILE, &hist);
	}
	if (hist.size != hsize)
		hist_resize(&hist, hsize);
	return (&hist);
}
