/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linefeed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:52:17 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 22:53:15 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			ft_linefeed(void)
{
	if (reset_buffer() == EXIT_SUCCESS)
		return (reset_prompt());
	// history_handler
	// satkins_parser(shell_env->line_buffer);
	// reset the buffer
	return (EXIT_SUCCESS);
}
