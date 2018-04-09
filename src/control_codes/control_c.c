/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:00:39 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/07 17:55:41 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_control.h"

int		control_c(void)
{

//	pid_t	owner;

//	owner = fcntl(STDOUT_FILENO, F_GETOWN);
//	kill(owner, SIGKILL);
	cursor_to_end(&g_shell_env.cursor);
	if (reset_prompt() == EXIT_FAILURE || reset_buffer() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
