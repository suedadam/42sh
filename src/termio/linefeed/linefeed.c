/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linefeed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:52:17 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/16 06:53:06 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linefeed.h"
#include "ft_proto.h"

int			ft_linefeed(void)
{
	int				ret;
	static char		*cache = NULL;

	if (g_shell_env.buffer->length)
		history_append_file(g_shell_env.buffer->buff);
	ft_restoretty();
	signal(SIGINT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	ft_printf_fd(STDOUT_FILENO, "\n");
	ret = manager(g_shell_env.buffer->buff, NULL);
	if (ret == EXIT_FAILURE || ret == EXIT_FAILURE_SOFT)
	{
		ft_printf("Error exiting...\n");
		return (EXIT_FAILURE);
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
