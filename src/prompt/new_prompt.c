/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:55:14 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 19:20:01 by asyed            ###   ########.fr       */
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
		cursor->buffer = cursor->buffer + length;
		g_shell_env.buffer->length = 0;
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
		free(pwd);
	}
	g_shell_env.prompt_length = n;
	cursor->position = 0;
	get_cursor_first_position();
	return (EXIT_SUCCESS);
}
