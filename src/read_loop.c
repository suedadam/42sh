/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:33:27 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/28 22:08:25 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		read_loop(t_terminf *shell_env)
{
	char	byte;
	int		mpass;

	anti = (void *)anti;
	mpass = 0;
	new_prompt(shell_env);
	// while (read(STDIN_FILENO, &byte, 1) == 1)
	// {
	// 	if ((byte == 27) || mpass)
	// 		read_multibyte(byte, &mpass, anti);
	// 	else if (byte == 12 && !mpass)
	// 		ft_clearscreen(anti);
	// 	else if (byte == 127 && !mpass)
	// 		ft_backspace(anti);
	// //	else if (byte == 39 || byte == 34)
	// //		quote_mode(byte);
	// 	else if (byte == '\n')
	// 		ft_passinput(anti);
	// 	else if (byte == 4 && !mpass)
	// 		break ;
	// 	else if (!mpass)
	// 		ft_printf("%lc", byte);
	// }
	while (read(STDIN_FILENO, &byte, 1) == 1)
	{
		if (byte == '\n')
		{
			if (carriage_return(shell_env, byte) == EXIT_FAILURE)
				new_prompt(shell_env);
		}
		else if (handle_keys(byte) == EXIT_FAILURE
				|| checktty(anti) == EXIT_FAILURE)
			reset_terminal(byte);
	}

	return (EXIT_SUCCESS);
}
