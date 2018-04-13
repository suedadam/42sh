/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:33:27 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/12 18:04:27 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maincontrol.h"
#include "ft_proto.h"

static int											checktty(void)
{
	return (EXIT_SUCCESS);
}

static int											reset_terminal(void)
{
	if (g_shell_env.shell_tty)
	{
		free(g_shell_env.shell_tty);
		g_shell_env.shell_tty = NULL;
	}
	return (init_shellenv());
}

static inline __attribute__((always_inline)) int	ft_c_dispatch(void)
{
	if (g_shell_env.buffer->buff[g_shell_env.buffer->length - 1] == '\\')
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
			return (reset_terminal());
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
		if (byte == 4 && !(*g_shell_env.buffer->buff))
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
