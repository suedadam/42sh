/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linefeed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:52:17 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/14 15:23:52 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linefeed.h"
#include "ft_proto.h"

int			ft_linefeed(void)
{
	int		ret;
	// g_shell_env.buffer.buff; //string of line

/*	history_handler()
**	satkins_parser(g_shell_env->line_buffer)
**	reset the buffer
*/
	ft_restoretty();
	ret = manager(g_shell_env.buffer->buff, NULL);
	g_shell_env.buffer->buff = NULL;
	if (ret == EXIT_FAILURE || ret == EXIT_FAILURE_SOFT)
	{
		//handle manager failure
		ft_printf("error exiting...\n");
		exit(0);
	}
	ft_setty();
	if (reset_buffer() == EXIT_SUCCESS)
		return (reset_prompt());
	return (EXIT_SUCCESS);
}
