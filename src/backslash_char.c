/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:29:45 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/01 20:01:34 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		backslash_char(void)
{
	g_shell_env.tokens.bslash = 0;
	back_prompt();
	return (EXIT_SUCCESS);
}
