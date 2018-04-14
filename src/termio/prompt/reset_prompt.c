/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:55:59 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/13 22:36:07 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"
#include "ft_proto.h"

int			reset_prompt(void)
{
	static char	*cache = NULL;

	if (!cache)
		cache = tgetstr("do", NULL);
	tputs(cache, 1, my_putchar);
	if (new_prompt(0))
		return (EXIT_FAILURE);
	get_cursor_first_position();
	bzero(&g_shell_env.tokens, sizeof(t_tokens));
	g_shell_env.cursor.wordloc = 0;
	return (EXIT_SUCCESS);
}
