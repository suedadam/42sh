/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:41:20 by sgardner          #+#    #+#             */
/*   Updated: 2018/04/07 02:11:14 by sgardner         ###   ########.fr       */
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
		offset = HPOS(hist->tail, -(max - 1) + i, hist->size);
		if (!tmp[offset].data)
			break ;
		hist->arr[i++] = tmp[offset];
	}
	free(tmp);
	hist->len = i;
	hist->size = nsize;
	hist->head = 0;
	hist->tail = (hist->len) ? hist->len - 1 : 0;
}
