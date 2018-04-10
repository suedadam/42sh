/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 18:04:57 by sgardner          #+#    #+#             */
/*   Updated: 2018/04/10 06:47:52 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "history.h"

static void		print_history(t_process *pinfo, char **av, t_bool range)
{
	t_hist	*hist;
	int		start;
	int		end;
	int		len;
	t_bool	rev;

	hist = hist_getall();
	if (!hist->len || !param_atoi(*av, &start))
		return (hist_error(0, *av, FALSE));
	end = hist->len;
	if (range && !param_atoi(*(++av), &end))
		return (hist_error(0, *av, FALSE));
	start = (start > hist->len) ? hist->len - 1 : start - 1;
	end = (range && end > hist->len) ? hist->len - 1 : end - 1;
	rev = (range && end < start);
	len = (range) ? MAX(start, end) - MIN(start, end) : end - start;
	hist_print(*pinfo->stdout, start, len + 1, rev);
}

static void		save_history(char *path, char mode)
{
	t_hist	*hist;

	hist = hist_getall();
	if (!path)
	{
		if (HISTFILE)
			path = HISTFILE;
		else
			return ;
	}
	if (mode == 'r')
		hist_load(path, hist);
	else if (mode == 'a')
		hist_save(path, hist, 0, TRUE);
	else if (mode == 'w')
		hist_save(path, hist, 0, FALSE);
}

static void		process_opt(t_process *pinfo, t_histopt *opt)
{
	int	n;

	if (opt->clear)
		hist_clear();
	else if (opt->del != NULL)
	{
		if (!param_atoi(opt->del, &n) || !hist_delete(n - 1))
			return (hist_error(0, opt->del, FALSE));
	}
	if (opt->io_mode)
		save_history(opt->save_target, opt->io_mode);
	if (opt->args)
		print_history(pinfo, opt->args, *(opt->args + 1) != NULL);
}

int				builtin_history(char **av, t_process *pinfo)
{
	t_histopt	opt;
	int			ac;
	char		f;

	ac = 0;
	while (av[ac])
		++ac;
	g_fderr = *pinfo->stderr;
	ft_memset(&opt, 0, sizeof(t_histopt));
	while ((f = ft_getopt(ac, av, "cd:a::r::w::")) > -1)
	{
		if (f == 'c')
			opt.clear = TRUE;
		else if (f == 'd')
			opt.del = g_optarg;
		else if (ft_strchr("anrw", (opt.io_mode = f)))
			opt.save_target = (g_optarg) ? g_optarg : HISTFILE;
		else
			hist_error(1, NULL, FALSE);
	}
	if (g_optind < ac)
		opt.args = &av[g_optind];
	process_opt(pinfo, &opt);
	g_fderr = STDERR_FILENO;
	return ((f == '?') ? 1 : 0);
}
