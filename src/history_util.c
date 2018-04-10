/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:41:20 by sgardner          #+#    #+#             */
/*   Updated: 2018/04/10 07:05:40 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "history.h"

void	hist_error(int errnum, char *param, t_bool fatal)
{
	const char			*prefix;
	const char			*msg;
	static const char	*histerr[] = {
		"history position out of range",
		"history [-c] [-d] <offset> [-arw] [filename] [start] [end]"
	};

	prefix = (errnum == 1) ? "usage" : "history";
	msg = (errnum < 0) ? sys_errlist[errno] : histerr[errnum];
	write(g_fderr, prefix, ft_strlen(prefix));
	write(g_fderr, ": ", 2);
	write(g_fderr, msg, ft_strlen(msg));
	if (param)
	{
		write(g_fderr, ": ", 2);
		write(g_fderr, param, ft_strlen(param));
	}
	write(g_fderr, "\n", 1);
	if (fatal)
		exit(1);
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
		HDEF_ERROR(FATAL);
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

t_bool	param_atoi(char *arg, int *n)
{
	long	i;

	i = 0;
	if (!*arg)
		return (FALSE);
	while (*arg)
	{
		if (!IS_DIGIT(*arg))
			return (FALSE);
		i = (i * 10) + (*arg++ - '0');
		if (i > INT_MAX)
			return (FALSE);
	}
	*n = (int)i;
	return (i > 0);
}
