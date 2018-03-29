/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 10:57:07 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/29 12:09:55 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		terminit(t_terminf *anti)
{
	int		ret;
	char	*buff;
//	char	*temp;

	ft_printf("%d\n", ERR);
	if (!(anti->term_buff = (char *)ft_memalloc(2048))
		|| !(buff = (char *)ft_memalloc(2048)))
		return (EXIT_FAILURE);
	anti->term_name = getenv("TERM");
	ret = tgetent(anti->term_buff, anti->term_name);
	if (ret < 0)
		g_ft_errnum = TGETN;
	else if (ret == 0)
		g_ft_errnum = TGETZ;
	/* for term_buff and tgoto */
	if (!(BC = tgetstr("le", &(anti->term_buff))))
		g_ft_errnum = TGETSTR;
	if (!(UP = tgetstr("up", &(anti->term_buff))))
		g_ft_errnum = TGETSTR;
	PC = 0;
	return (((ret > 0) && (!g_ft_errnum)) ? EXIT_SUCCESS : EXIT_FAILURE);
}

int		quote_mode(char byte)
{
	char	*temp;

	temp = tgetstr("do", 0);
	tputs(temp, 1, my_stupidput);
	if (byte == '\'')
		ft_printf("quote> ");
	else
		ft_printf("dquote> ");
	return (EXIT_SUCCESS);
}

int static	init_env(t_terminf	*shell_env)
{
	if (!(shell_env = (t_terminf *)ft_memalloc(sizeof(struct termios)))
		|| !(shell_env->term_name = getenv("TERM"))
		|| tgetent(NULL, name_term) == ERR
		|| !(line_buffer = (char *)ft_memalloc(sizeof(char) * 4096)))
		retrn (EXIT_FAILURE);
	shell_env->cursor.c = 0;
	shell_env->cursor.l = 0;
	return (EXIT_SUCCESS);
}

/*
** isatty returns 0 when it fails, and sets errno
** tcgetattr returns -1 on failure and sets errno
*/

int			io_init(t_terminf *anti)
{
	if (!(anti->antishell = ft_memalloc(sizeof(struct termios)))
		|| (!(isatty(STDIN_FILENO)))
		|| ((tcgetattr(STDIN_FILENO, &anti->og)) < 0)
		|| (!(anti->antishell = (struct termios *)ft_memcpy(anti->antishell,
				&anti->og, sizeof(struct termios))))
		|| (ft_setty(anti) == EXIT_FAILURE))
	{
		ft_printf("fail\n");
		g_ft_errnum = SYSERR;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
** Welcome to the shitty shell.  I am your host, anti.
** To communicate around here, these parts shout at each other with:
** EXIT_SUCCESS = 0 and
** EXIT_FAILURE = 1
*/

int		main(void)
{
	t_terminf	anti;

	ft_bzero(&anti, sizeof(t_terminf));
	if (io_init(&anti) == EXIT_FAILURE
		|| shsignal_handlers() == EXIT_FAILURE
		|| terminit(&anti) == EXIT_FAILURE
		|| read_loop(&anti) == EXIT_FAILURE
		|| ft_restoretty(&anti) == EXIT_FAILURE)
//		|| termloop(&anti) <= 0) == EXIT_FAILURE
		ft_terror();
	return (0);
}
