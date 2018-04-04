/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 21:16:29 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/03 21:22:20 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		init_tokens(void)
{
	g_shell_env.tokens.mpass = 0;
	g_shell_env.tokens.bslash = 0;
	g_shell_env.tokens.control_v = 0;
	g_shell_env.tokens.quote = 0;
	g_shell_env.tokens.dquote = 0;
}
