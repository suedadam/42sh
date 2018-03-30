/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linemove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:44:17 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/29 18:03:54 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		ft_linemove(char byte)
{
	if (byte == 'C')
		cursor_to_left(&g_shell_env.cursor);
	else if (byte == 'D')
		cursor_to_right(&g_shell_env.cursor);
	else if (byte == 72)
		cursor_to_home(&g_shell_env.cursor);
	else if (byte == 70)
		cursor_to_end(&g_shell_env.cursor);
}
