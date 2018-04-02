/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:38:34 by tle-huu-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/04/01 20:02:03 by tle-huu-         ###   ########.fr       */
=======
/*   Updated: 2018/04/01 20:01:33 by nkouris          ###   ########.fr       */
>>>>>>> 9755dd5dd23c859f55612508575fc0c5fb4a4f81
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		new_prompt(void)
{
	char	pwd[4096];
	int		n;

	getcwd(pwd, 4096);
	get_window_size();
	n = ft_printf("42sh [%s] %% ", pwd);
	g_shell_env.prompt_length = n;
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
	new_prompt();
	get_cursor_first_position();
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
