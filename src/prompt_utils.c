/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:38:34 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/03 17:14:00 by tle-huu-         ###   ########.fr       */
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
		cursor->buffer = &g_shell_env.buffer->buff[length];
		n = ft_printf("%s", prompt);
	}
	else
		n = ft_printf("42sh [%s] %% ", pwd);
	// g_shell_env.prompt_length = n;
	cursor->position = 0;
	get_cursor_first_position();
	/*
	** trying to fix the very small window size_t

	** update_end_of_screen();
	** move_cursor(&g_shell_env.cursor);

	*/
}

void		reset_prompt()
{
	char	*temp;

	temp = tgetstr("do", 0);
	tputs(temp, 1, my_putchar);
	new_prompt(0);
	// get_cursor_first_position();
}

void		back_prompt(void)
{
	char	*temp;
	int		n;

	temp = tgetstr("do", 0);
	tputs(temp, 1, my_putchar);
	n = ft_printf("> ");
	g_shell_env.prompt_length = n;
	get_cursor_first_position();
}
