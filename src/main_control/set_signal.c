/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:25:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/09 16:22:58 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maincontrol.h"
#include "ft_proto.h"

static void	_y(__attribute__((unused)) int c)
{
	yank(g_shell_env.paperweight.buff);
}

int			shsignal_handlers(void)
{
	signal(SIGINT, (void (*)(int))&control_c);
	signal(SIGTSTP, &_y);
	signal(SIGCONT, SIG_IGN);
	signal(SIGWINCH, (void (*)(int))&cursor_locate);
	return (EXIT_SUCCESS);
}
