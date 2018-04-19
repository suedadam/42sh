/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:33:27 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/18 20:44:20 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maincontrol.h"
#include "ft_proto.h"

static int											checktty(void)
{
	return (EXIT_SUCCESS);
}

static int											builtin_exit(char byte)
{
	if (byte == 10 && ft_strequ("exit", g_shell_env.buffer->buff))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

static int											reset_terminal(void)
{
	if (g_shell_env.shell_tty)
	{
		meta_free(g_shell_env.shell_tty);
		g_shell_env.shell_tty = NULL;
	}
	return (init_shellenv());
}

static inline __attribute__((always_inline)) int	ft_c_dispatch(void)
{
	verify_hanging();
	if (g_shell_env.cursor.position
			&& g_shell_env.buffer->buff[g_shell_env.buffer->length - 1] == '\n')
		return (drop_prompt("> "));
	else if (T_QUOTE | T_DQUOTE)
		return (quote_mode());
	else if (T_OPAREN)
		return (drop_prompt("subsh> "));
	else if (T_OCURLY)
		return (drop_prompt("curly> "));
	else if (T_PIPE)
		return (drop_prompt("pipe> "));
	else
	{
		if (ft_linefeed() == EXIT_FAILURE
			|| checktty() == EXIT_FAILURE)
		{
			reset_terminal();
			return (new_prompt(0));
		}
	}
	return (EXIT_SUCCESS);
}

/*
** init_buffer() already zero'd out the tokens.
*/

int													ft_read_loop(void)
{
	char	byte;
	int		ret;

	if (new_prompt(0) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while ((ret = read(STDIN_FILENO, &byte, 1)) == 1)
	{
		if ((byte == 4 || (builtin_exit(byte) == EXIT_SUCCESS))
			&& (!(*g_shell_env.buffer->buff &&
			(builtin_exit(byte) == EXIT_FAILURE))))
		{
			if (reset_prompt() == EXIT_FAILURE)
				return (EXIT_FAILURE);
			break ;
		}
		else if (byte == 10)
			ret = ft_c_dispatch();
		else if ((ret = handle_keys(byte)) == EXIT_FAILURE)
			ret = reset_terminal();
		if (ret == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (ret < 0)
		g_ft_errnum = SYSERR;
	return (g_ft_errnum ? EXIT_FAILURE : EXIT_SUCCESS);
}
