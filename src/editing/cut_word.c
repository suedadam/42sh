/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:47:52 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 12:15:40 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void 			cut_word_before_cursor(void)
{
	char		*buffer;
	t_cursor	*cursor;
	size_t		og_pos;

	cursor = &g_shell_env.cursor;
	buffer = cursor->buffer;
	og_pos = cursor->position;
	while (cursor->position && buffer[cursor->position] == ' ')
		cursor_to_left(cursor);
	while (cursor->position && buffer[cursor->position] != ' ')
		cursor_to_left(cursor);
	g_shell_env.paperweight.buff = ft_strsub(buffer, cursor->position,
		og_pos - cursor->position + 1);
	g_shell_env.paperweight.length = ft_strlen(g_shell_env.paperweight.buff);
	g_shell_env.paperweight.max_size = g_shell_env.paperweight.length;
	while (cursor->position != og_pos)
	{
		ft_delete(-1);
		og_pos--;
	}
}
