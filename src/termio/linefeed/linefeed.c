/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linefeed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:52:17 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/15 11:18:17 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linefeed.h"
#include "ft_proto.h"

int			ft_linefeed(void)
{
	int		ret;
	static char	*cache = NULL;	

	if (g_shell_env.buffer->length)
		history_append_file(g_shell_env.buffer->buff);
	g_shell_env.history_var.current_history_cmd = NULL;
	ft_restoretty();
	signal(SIGINT, SIG_IGN);
	// signal(SIGTSTP, SIG_IGN);
	ft_printf_fd(STDOUT_FILENO, "\n");
	// ft_printf("Buffer = \"%s\"\n", g_shell_env.buffer->buff);
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
