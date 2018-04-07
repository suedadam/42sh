/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:55:14 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/07 16:02:29 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			new_prompt(char *prompt)
{
	char		*pwd;
	t_cursor	*cursor;
	size_t		length;
	int			n;

	if (get_window_size() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	cursor = &(g_shell_env.cursor);
	if (prompt)
	{
		length = g_shell_env.buffer->length;
		cursor->buffer += cursor->buffer_length;
		cursor->buffer_length = 0;
		n = ft_printf("%s", prompt);
	}
	else
	{
		if (!(pwd = getcwd(NULL, 0)))
		{
			g_ft_errnum = TERMGET;
			return (EXIT_FAILURE);
		}
		n = ft_printf("42sh [%s] %% ", pwd);
		g_shell_env.cursor.buffer_length = g_shell_env.buffer->length;
		cursor->buffer = g_shell_env.buffer->buff;
		free(pwd);
		pwd = NULL;
	}
	g_shell_env.prompt_length = n;
	cursor->position = 0;
	get_cursor_first_position();
	return (EXIT_SUCCESS);
}
