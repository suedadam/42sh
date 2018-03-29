/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 10:57:07 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/29 14:37:21 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

/*
** Termcaps database is initialized here and reference to it is saved
*/

static int	init_termcaps(t_terminf *shell_env)
{
	int		ret;
	char	*buff;

	if (!(shell_env->term_buff = (char *)ft_memalloc(2048))
		|| !(buff = (char *)ft_memalloc(2048))
		|| !(shell_env->term_name = getenv("TERM")))
		return (EXIT_FAILURE);
	ret = tgetent(shell_env->term_buff, shell_env->term_name);
	if (ret < 0)
		g_ft_errnum = TGETN;
	else if (ret == 0)
		g_ft_errnum = TGETZ;
	return (((ret > 0) && (!g_ft_errnum)) ? EXIT_SUCCESS : EXIT_FAILURE);
}

/*
**	Shell is initialized here
**	Original terminal attr are initialized and stored in the shell_env struct
**	New terminal attr are set in ft_setty
**	Line buffer is initialized for the first time
**	Cursor is already initialized to zero with the ft_memalloc in shell_env
*/

static int	init_shellenv(t_terminf *shell_env)
{
	if (!(shell_env->shell_tty = ft_memalloc(sizeof(struct termios)))
		|| (!(isatty(STDIN_FILENO)))
		|| ((tcgetattr(STDIN_FILENO, &shell_env->original_tty)) < 0)
		|| (!(ft_memcpy(shell_env->shell_tty, &original_tty,
					sizeof(struct termios))))
		|| (ft_setty(shell_env) == EXIT_FAILURE)
		|| ((init_buffer(shell_env) == EXIT_FAILURE)))
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
	t_terminf	shell_env;

	g_shell_env = &shell_env;
	ft_bzero(&shell_env, sizeof(t_terminf));
	if (init_shellenv(&shell_env) == EXIT_FAILURE
		|| shsignal_handlers() == EXIT_FAILURE
		|| init_termcaps(&shell_env) == EXIT_FAILURE
		|| read_loop(&shell_env) == EXIT_FAILURE
		|| ft_restoretty(&shell_env) == EXIT_FAILURE)
		ft_terror();
	return (0);
}
