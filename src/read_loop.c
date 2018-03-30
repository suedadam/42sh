/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:33:27 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/29 17:47:50 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		read_loop(void)
{
	char	byte;
	int		mpass;
	int		bslash;

	mpass = 0;
	bslash = 0;
	new_prompt();
	while (read(STDIN_FILENO, &byte, 1) == 1)
	{
		if (byte == '\n' && !backslash)
		{
			if (carriage_return(gbyte) == EXIT_FAILURE)
				new_prompt();
		}
		else if (handle_keys(byte, &mpass) == EXIT_FAILURE
				|| checktty() == EXIT_FAILURE)
			reset_terminal();
	}
	return (EXIT_SUCCESS);
}
