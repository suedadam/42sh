/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:33:27 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/02 12:07:01 by nkouris          ###   ########.fr       */
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

int				read_loop(void)
{
	char	byte;

	T_MPASS = 0;
	T_BSLASH = 0;
	new_prompt();
	while (read(STDIN_FILENO, &byte, 1) == 1)
	{
		if (byte == 4)
		{
			reset_prompt();
			break ;
		}
		else if (byte == 10 && T_BSLASH)
			backslash_char();
		else if (byte == 10 && (T_QUOTE ^ T_DQUOTE))
			quote_mode(byte);
		else if (byte == 10)
		{
			if (ft_carriage_return() == EXIT_FAILURE)
				new_prompt();
		}
		else if (handle_keys(byte) == EXIT_FAILURE
				|| checktty() == EXIT_FAILURE)
			reset_terminal();
	}
	return (EXIT_SUCCESS);
}
