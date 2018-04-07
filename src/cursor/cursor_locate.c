/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_locate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:38:18 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 21:06:42 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

/*
** Handle failures. Print to stderr if failure.
*/

void		cursor_locate(void)
{
	int		og_curpos;

	og_curpos = g_shell_env.cursor.position;
	cursor_to_home(&g_shell_env.cursor);
	get_window_size();
	get_cursor_first_position();
	clear_below();
	cursor_to_left_margin();
	new_prompt(0);
	g_shell_env.cursor.position = og_curpos;
	reprint_buffer();
}
