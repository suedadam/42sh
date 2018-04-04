/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 10:57:07 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/03 21:24:23 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

/*
** Termcaps database is initialized here and reference to it is saved
*/

static int	init_termcaps(void)
{
	int		ret;
	char	*buff;

	if (!(g_shell_env.term_buff = (char *)ft_memalloc(2048))
		|| !(buff = (char *)ft_memalloc(2048))
		|| !(g_shell_env.term_name = getenv("TERM")))
		return (EXIT_FAILURE);
	ret = tgetent(g_shell_env.term_buff, g_shell_env.term_name);
	if (ret < 0)
		g_ft_errnum = TGETN;
	else if (ret == 0)
		g_ft_errnum = TGETZ;
	return (((ret > 0) && (!g_ft_errnum)) ? EXIT_SUCCESS : EXIT_FAILURE);
}

/*
**	Shell is initialized here
**	Original terminal attr are initialized and stored in the g_shell_env.truct
**	New terminal attr are set in ft_setty
**	Line buffer is initialized for the first time
**	Cursor is already initialized to zero with the ft_memalloc in shell_env
*/

static int	init_shellenv(void)
{
	if (!(g_shell_env.shell_tty = ft_memalloc(sizeof(struct termios)))
		|| (!(isatty(STDIN_FILENO)))
		|| ((tcgetattr(STDIN_FILENO, &g_shell_env.original_tty)) < 0)
		|| (!(ft_memcpy(g_shell_env.shell_tty, &g_shell_env.original_tty,
					sizeof(struct termios))))
		|| (ft_setty() == EXIT_FAILURE)
		|| (init_buffer() == EXIT_FAILURE)
		|| (get_window_size() == EXIT_FAILURE))
	{
		g_ft_errnum = SYSERR;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
** All buffers and info pertinent to the shell is contained in shell_env
** Comminicate through the chain of returns with EXIT_SUCCESS = 0 and
** EXIT_FAILURE = 1 for ints, and NULL / 0
*/

int			main(void)
{
	ft_bzero(&g_shell_env, sizeof(t_terminf));
	if (init_shellenv() == EXIT_FAILURE
		|| shsignal_handlers() == EXIT_FAILURE
		|| init_termcaps() == EXIT_FAILURE
		|| read_loop() == EXIT_FAILURE
		|| ft_restoretty() == EXIT_FAILURE)
		ft_terror();
	return (0);
}
