/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:40:21 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/29 16:23:21 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static int		multibyte(t_terminf *shell_env, char byte, int *mpass)
{
	if (*mpass == 0
		|| (*mpass == 1 && byte == '['))
	{
		(*mpass)++;
		return (EXIT_SUCCESS);
	}
	else if (*mpass == 1 && byte != '[')
	{
		one_byte(shell_env, byte);
		return (EXIT_SUCCESS);
	}
	// jump table
}

static int		regular_text(t_terminf *shell_env, char byte)
{
	int			i;
	t_buffer	*buffer;

	i = 0;
	buffer = shell_env->buffer;
	if (buffer->len_buffer == buffer->maxsize_buffer)
		resize_buffer(buffer);
	// print byte on the cursor, find a solution to editing line
	if (shell_env->line_buffer[shell_env->cursor.c])
	if (!shell_env->line_buffer[shell_env->cursor.c])
		shell_env->line_buffer[shell_env->cursor.c] = byte;
	else
	{
		i = shell_env->length_buffer;
		while (i > shell_env->cursor.c)
		{
			shell_env->line_buffer[i] = shell_env->line_buffer[i - 1];
			i--;
		}
		shell_env->line_buffer[shell_env->cursor.c] = byte;
	}
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

int				handle_keys(t_terminf *shell_env, char byte, int *mpass)
{
	int		ret;
	int		token;

	ret = EXIT_SUCCESS;
	token = 0;
	if (byte == 27)
		ret = multibyte(shell_env, byte, mpass);
	else
		ret = one_byte(shell_env, byte);
	return (ret);
}
