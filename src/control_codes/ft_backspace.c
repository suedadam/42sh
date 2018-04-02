/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:19:32 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/01 20:01:32 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

// int			ft_backspace(char byte)
// {
// 	t_cursor	*cursor;
// 	char		*buffer;
// 	int			ret;
//
// 	ret = EXIT_SUCCESS;
// 	byte = 0;
// 	if (g_shell_env.buffer->length)
// 	{	buffer = g_shell_env.buffer->buff;
// 		cursor = &(g_shell_env.cursor);
// 		ft_memmove(buffer + cursor->position - 1, buffer + cursor->position,
// 				g_shell_env.buffer->max_size - cursor->position - 1);
// 		cursor->position--;
// 		ret = tputs(tgetstr("dc", 0), 1, &my_putchar);
// 		g_shell_env.buffer->length--;
// 	}
// 	return (ret == ERR ? EXIT_FAILURE : EXIT_SUCCESS);
// }

int			ft_backspace(void)
{
	t_cursor	*cursor;

	cursor = &(g_shell_env.cursor);
	if (cursor->position > 0)
	{
		cursor->position--;
		return (ft_delete(-1));
	}
	return (EXIT_SUCCESS);
}
