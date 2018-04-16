/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:25:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/15 23:19:45 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maincontrol.h"
#include "ft_proto.h"

static void	_y(__attribute__((unused)) int c)
{
	yank(g_shell_env.paperweight.buff);
}

inline __attribute__((always_inline)) int			signaldef_handlers(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGCONT, SIG_DFL);
	signal(SIGWINCH, SIG_DFL);
	return (EXIT_SUCCESS);
}


inline __attribute__((always_inline)) int			shsignal_handlers(void)
{
	signal(SIGINT, (void (*)(int))&control_c);
	signal(SIGTSTP, &_y);
	signal(SIGCONT, SIG_IGN);
	signal(SIGWINCH, (void (*)(int))&cursor_locate);
	return (EXIT_SUCCESS);
}
