/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linefeed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:52:17 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/14 20:01:33 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linefeed.h"
#include "ft_proto.h"

int			ft_linefeed(void)
{
	int		ret;
	static char	*cache = NULL;	
	// g_shell_env.buffer.buff; //string of line

/*	history_handler()
**	satkins_parser(g_shell_env->line_buffer)
**	reset the buffer
*/
	ft_restoretty();
	signal(SIGINT, SIG_IGN);
	// signal(SIGTSTP, SIG_IGN);
	ft_printf_fd(STDOUT_FILENO, "\n");
	ret = manager(g_shell_env.buffer->buff, NULL);
	g_shell_env.buffer->buff = NULL;
	if (ret == EXIT_FAILURE || ret == EXIT_FAILURE_SOFT)
	{
		//handle manager failure
		ft_printf("error exiting...\n");
		exit(0);
	}
	ft_setty();
	if (!cache)
		cache = tgetstr("up", NULL);
	tputs(cache, 1, my_putchar);
	shsignal_handlers();
	if (reset_buffer() == EXIT_SUCCESS)
		return (reset_prompt());
	return (EXIT_SUCCESS);
}
