/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:38:47 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 19:50:24 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cursor.h"

void	move_cursor(t_cursor *cursor)
{
	static char	*cache = NULL;
	int			og_col;
	int			og_line;
	int			new_col;
	int			new_line;

	if (!cache)
		cache = tgetstr("cm", NULL);
	og_line = cursor->og_position.y;
	og_col = cursor->og_position.x;
	new_col = og_col + cursor->position;
	new_line = og_line + new_col / (g_shell_env.window.ws_col);
	new_col %= g_shell_env.window.ws_col;
	tputs(tgoto(cache, new_col, new_line), 0, &my_putchar);
}
