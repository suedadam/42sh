/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linemove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:44:17 by nkouris           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/30 13:16:24 by nkouris          ###   ########.fr       */
=======
/*   Updated: 2018/03/31 15:18:20 by tle-huu-         ###   ########.fr       */
>>>>>>> termio
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		ft_linemove(char byte)
{
	if (byte == 'D')
		cursor_to_left(&g_shell_env.cursor);
	else if (byte == 'C')
		cursor_to_right(&g_shell_env.cursor);
	else if (byte == 72)
		cursor_to_home(&g_shell_env.cursor);
	else if (byte == 70)
		cursor_to_end(&g_shell_env.cursor);
	return (EXIT_SUCCESS);
}
