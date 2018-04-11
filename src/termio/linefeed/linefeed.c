/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linefeed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:52:17 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/11 10:28:40 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linefeed.h"
#include "ft_proto.h"

int			ft_linefeed(void)
{
	t_ast	*forest;

	forest = parser(g_shell_env.buffer.buff) /* returns ast type */
	if (reset_buffer() == EXIT_SUCCESS)
		return (reset_prompt());
/*	history_handler()
**	satkins_parser(shell_env->line_buffer)
**	reset the buffer
*/
	return (EXIT_SUCCESS);
}
