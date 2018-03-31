/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:19:32 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/30 11:21:48 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			ft_backspace(char byte)
{
	t_cursor	*cursor;
	char		*buffer;
	int			ret;

	ret = EXIT_SUCCESS;
	if (g_shell_env.buffer->length)
	{	buffer = g_shell_env.buffer->buff;
		cursor = &(g_shell_env.cursor);
		ft_memmove(buffer + cursor->position - 1, buffer + cursor->position,
				g_shell_env.buffer->max_size - cursor->position - 1);
		cursor->position--;
		ret = tputs(tgetstr("dc", 0), 1, &my_putchar);
		g_shell_env.buffer->length--;
	}
	return (ret == ERR ? EXIT_FAILURE : EXIT_SUCCESS);
}
