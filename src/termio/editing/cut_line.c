/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:46:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/09 19:30:41 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_editing.h"
#include "ft_proto.h"

void		cut_line_after_cursor(void)
{
	char		*buffer;
	t_cursor	*cursor;

	cursor = &g_shell_env.cursor;
	if ((buffer = cursor->buffer))
	{
		meta_free(PAPER.buff);
		PAPER.buff = NULL;
		PAPER.buff = ft_strdup(buffer + cursor->position);
		PAPER.length = ft_strlen(PAPER.buff);
		PAPER.max_size = PAPER.length;
		while (cursor->buffer_length != cursor->position)
			ft_delete(-1);
	}
}

void		cut_line_before_cursor(void)
{
	char		*buffer;
	t_cursor	*cursor;

	cursor = &g_shell_env.cursor;
	if ((buffer = cursor->buffer))
	{
		meta_free(PAPER.buff);
		PAPER.buff = NULL;
		PAPER.buff = ft_strsub(buffer, 0, cursor->position);
		PAPER.length = ft_strlen(PAPER.buff);
		PAPER.max_size = PAPER.length;
		while (cursor->position)
			ft_backspace();
	}
}
