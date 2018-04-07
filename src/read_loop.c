/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:33:27 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/06 19:27:06 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static int		checktty(void)
{
	return (EXIT_SUCCESS);
}

static int		reset_terminal(void)
{
	return (EXIT_SUCCESS);
}

static inline __attribute__((always_inline)) void ft_c_dispatch()
{
	if (T_BSLASH)
		backslash_char();
	else if (T_QUOTE | T_DQUOTE)
		quote_mode();
	else
	{
		if (ft_linefeed() == EXIT_FAILURE
			|| checktty() == EXIT_FAILURE)
			reset_terminal();
	}
}

/*
** init_buffer() already zero'd out the tokens.
*/

int				ft_read_loop(void)
{
	char	byte;
	int		ret;

	if (new_prompt(0) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while ((ret = read(STDIN_FILENO, &byte, 1)) == 1)
	{
/*	ft_printf("byte : <%d>\n", byte); */
		if (byte == 4 && !(*g_shell_env.buffer->buff))
		{
			if (reset_prompt())
				return (EXIT_FAILURE);
			break ;
		}
		else if (byte == 10)
			ft_c_dispatch();
		else if (handle_keys(byte) == EXIT_FAILURE)
			reset_terminal();
	}
	if (ret < 0)
	{
		g_ft_errnum = SYSERR;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
