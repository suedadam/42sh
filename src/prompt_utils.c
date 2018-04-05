/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:38:34 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/04 18:39:57 by nkouris          ###   ########.fr       */
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
	/*
	** trying to fix the very small window size_t

	** update_end_of_screen();
	** move_cursor(&g_shell_env.cursor);

	*/
}

void		reset_prompt(void)
{
	char	*temp;

	temp = tgetstr("do", 0);
	tputs(temp, 1, my_putchar);
	new_prompt(0);
	get_cursor_first_position();
}

void		back_prompt(void)
{
	char	*temp;
	// int		n;

	temp = tgetstr("do", 0);
	tputs(temp, 1, my_putchar);
	new_prompt("> ");
	// n = ft_printf("> ");
	// g_shell_env.prompt_length = n;
	get_cursor_first_position();
}

void		resize_prompt(void)
{
	char	*temp;

	temp = 0;

	cursor_to_home(&g_shell_env.cursor);
/*	cursor_to_home(&g_shell_env.cursor);
	temp = tgetstr("dl", 0);
	tputs(temp, 1, &my_putchar);
	temp = tgetstr("cl", 0);
	tputs(temp, 1, my_putchar);
	get_window_size();
	*/
}
