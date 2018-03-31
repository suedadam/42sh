/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:38:34 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/30 11:48:13 by tle-huu-         ###   ########.fr       */
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
