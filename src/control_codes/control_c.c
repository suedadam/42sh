/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:00:39 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 22:48:03 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		control_c(void)
{
	cursor_to_end(&g_shell_env.cursor);
	if (reset_buffer() == EXIT_FAILURE
		|| reset_prompt() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
