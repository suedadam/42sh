/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:33:27 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/29 16:23:22 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		read_loop(t_terminf *shell_env)
{
	char	byte;
	int		mpass;
	int		bslash;

	mpass = 0;
	bslash = 0;
	new_prompt(shell_env);
	while (read(STDIN_FILENO, &byte, 1) == 1)
	{
		if (byte == '\n' && !backslash)
		{
			if (carriage_return(shell_env, byte) == EXIT_FAILURE)
				new_prompt(shell_env);
		}
		else if (handle_keys(byte, &mpass) == EXIT_FAILURE
				|| checktty(shell_env) == EXIT_FAILURE)
			reset_terminal(shell_env);
	}
	return (EXIT_SUCCESS);
}
