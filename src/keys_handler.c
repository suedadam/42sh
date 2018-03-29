/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:40:21 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/28 21:49:21 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static int		multibyte(t_terminf *shell_env, char byte, int *token)
{
	// jump table
}

static int		regular_text(t_terminf *shell_env, char byte)
{
	// print byte
	// add to the line_buffer --> handle with cursor pointer and
			//resizing buffer if necessary
}

static int		control_char(t_terminf *shell_env, char byte)
{
	// jump table
}


static int		one_byte(t_terminf *shell_env, char byte)
{
	int		ret;

	ret = EXIT_SUCCESS;
	if (byte >= 32 && byte <= 126)
		ret = one_byte(shell_env, byte);
	if (byte < 32 || byte == 127)
		ret = control_char(shell_env, byte);
	return (ret);
}

int				handle_keys(t_terminf *shell_env, char byte)
{
	int		ret;
	int		token;

	ret = EXIT_SUCCESS;
	token = 0;
	if (byte == 27)
		ret = multibyte(shell_env, byte, &token);
	else
		ret = one_byte(shell_env, byte);
	return (ret);
}
