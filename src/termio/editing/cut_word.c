/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:47:52 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/16 02:48:50 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_editing.h"
#include "ft_proto.h"

void		cut_word_before_cursor(void)
{
	char		*buffer;
	t_cursor	*cursor;
	size_t		og_pos;

	cursor = &g_shell_env.cursor;
	og_pos = cursor->position;
	if ((buffer = cursor->buffer))
	{
		if (cursor->position && buffer[cursor->position] != ' '
			&& buffer[cursor->position - 1] == ' ')
			cursor_to_left(cursor);
		while (cursor->position && buffer[cursor->position] == ' ')
			cursor_to_left(cursor);
		while (cursor->position && buffer[cursor->position] != ' ')
			cursor_to_left(cursor);
		if (cursor->position)
			cursor_to_right(cursor);
		PAPER.buff = ft_strsub(buffer, cursor->position,
			og_pos - cursor->position);
		PAPER.length = ft_strlen(PAPER.buff);
		PAPER.max_size = PAPER.length;
		while (cursor->position != og_pos--)
			ft_delete(-1);
	}
}
