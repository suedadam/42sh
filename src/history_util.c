/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:41:20 by sgardner          #+#    #+#             */
/*   Updated: 2018/04/08 04:44:58 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "history.h"

void	hist_error(int errnum, void *param, t_bool isnum)
{
	static const char *errmsg[] = {
		"history position out of range"
	};

	if (isnum)
		param = ft_itoa(*(int *)param + 1);
	sh_error("history", errmsg[errnum], (const char *)param);
	if (isnum)
		free(param);
}

char	*hist_get_prefix(t_hist *hist, int max)
{
	static char	pre[16];
	int			n;

	n = 0;
	++max;
	ft_memset(pre, ' ', 15);
	while (max)
	{
		++n;
		max /= 10;
	}
	pre[n + 5] = '\0';
	return (&pre[0]);
}

void	hist_resize(t_hist *hist, int nsize)
{
	t_log	*tmp;
	int		max;
	int		offset;
	int		i;

	tmp = hist->arr;
	if (!(hist->arr = ft_memalloc(sizeof(t_log) * nsize)))
		DEFAULT_ERROR(FATAL);
	i = 0;
	max = (nsize > hist->len) ? hist->len : nsize;
	while (i < max)
	{
		if (!tmp[(offset = HPOS(hist->tail, -(max - 1) + i, hist->size))].data)
			break ;
		hist->arr[i++] = tmp[offset];
	}
	max = hist->len - i;
	hist->len = i;
	i = 0;
	while (i < max)
		free(tmp[HPOS(hist->head, i++, hist->size)].data);
	free(tmp);
	hist->size = nsize;
	hist->head = 0;
	hist->tail = (hist->len) ? hist->len - 1 : 0;
}

t_hist	*hist_scale(t_hist *hist)
{
	int	size;

	if (hist->size > hist->maxsize)
		hist_resize(hist, hist->maxsize);
	size = hist->size / 2;
	if (hist->len < size - GROWTH_PAD)
	{
		while (hist->len < (size / 2) - GROWTH_PAD)
			size /= 2;
		hist_resize(hist, size);
	}
	return (hist);
}
