/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:38:34 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/31 10:42:55 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		new_prompt(void)
{
	char	pwd[4096];
	int		n;

	getcwd(pwd, 4096);
	n = ft_printf("42sh [%s] %% ", pwd);
	g_shell_env.prompt_length = n;
	get_cursor_first_position();
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
