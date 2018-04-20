/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linefeed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:52:17 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/20 15:42:44 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linefeed.h"
#include "ft_proto.h"

static void	ft_execprep(void)
{
	ft_restoretty();
	signal(SIGINT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	ft_printf_fd(STDOUT_FILENO, "\n");
}

int			ft_linefeed(void)
{
	int				ret;
	static char		*cache = NULL;

	if (g_shell_env.buffer->length)
		history_append_file(g_shell_env.buffer->buff);
	ft_execprep();
	ret = manager(g_shell_env.buffer->buff, NULL);
	if (ret == EXIT_FAILURE || ret == EXIT_FAILURE_SOFT)
	{
		ft_printf("Error: %s\n", ft_strerror(errno));
		shsignal_handlers();
		return (EXIT_FAILURE);
	}
	if (!cache)
		cache = tgetstr("up", NULL);
	tputs(cache, 1, my_putchar);
	ft_setty();
	shsignal_handlers();
	if (reset_buffer() == EXIT_SUCCESS)
		return (reset_prompt());
	return (EXIT_SUCCESS);
}
