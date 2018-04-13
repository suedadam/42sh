/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linefeed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:52:17 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/12 00:07:53 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linefeed.h"
#include "ft_proto.h"

int			ft_linefeed(void)
{
	// g_shell_env.buffer.buff; //string of line
	if (reset_buffer() == EXIT_SUCCESS)
		return (reset_prompt());
/*	history_handler()
**	satkins_parser(g_shell_env->line_buffer)
**	reset the buffer
*/
	return (EXIT_SUCCESS);
}
