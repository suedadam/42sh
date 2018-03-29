/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:38:34 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/29 13:38:18 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		new_prompt(t_terminf *shell_env)
{
	char	pwd[4096];

	pwd = getcwd(pwd, 4096);
	ft_printf("42sh [%s] %% ", pwd);
	g_shell_env->prompt_length = ft_strlen(pwd) + 10;
}
