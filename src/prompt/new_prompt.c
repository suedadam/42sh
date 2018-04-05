/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:55:14 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 11:55:41 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		new_prompt(char *prompt)
{
	char		pwd[4096];
	t_cursor	*cursor;
	size_t		length;
	int			n;

	getcwd(pwd, 4096);
	get_window_size();
	cursor = &(g_shell_env.cursor);
	if (prompt)
	{
		length = g_shell_env.buffer->length;
		cursor->buffer = cursor->buffer + length;
		g_shell_env.buffer->length = 0;
		n = ft_printf("%s", prompt);
	}
	else
		n = ft_printf("42sh [%s] %% ", pwd);
	g_shell_env.prompt_length = n;
	cursor->position = 0;
	get_cursor_first_position();
//	init_tokens();
}
