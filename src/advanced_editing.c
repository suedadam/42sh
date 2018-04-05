/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_pasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:25:22 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/04 16:59:48 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void			yank(char *buffer)
{
	ft_putstr_fd(buffer, 0);
}

void 			cut_line_after_cursor(void)
{
	char		*buffer;
	t_cursor	*cursor;

	cursor = &g_shell_env.cursor;
	buffer = cursor->buffer;
	g_shell_env.paperweight.buff = ft_strdup(buffer + cursor->position);
	g_shell_env.paperweight.length = ft_strlen(g_shell_env.paperweight.buff);
	g_shell_env.paperweight.max = g_shell_env.paperweight.length;
	while (g_shell_env.buffer->length != cursor->position)
		ft_delete(-1);
}

void 			cut_line_before_cursor(void)
{
	char		*buffer;
	t_cursor	*cursor;

	cursor = &g_shell_env.cursor;
	buffer = cursor->buffer;
	g_shell_env.paperweight.buff = ft_strsub(buffer, 0, cursor_position + 1);
	g_shell_env.paperweight.length = ft_strlen(g_shell_env.paperweight.buff);
	g_shell_env.paperweight.max = g_shell_env.paperweight.length;
	while (g_shell_env.buffer->length != cursor->position)
		ft_delete(1);
}

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
	g_shell_env.paperweight->buff = ft_strsub(buffer, cursor->position,
		og_pos - cursor->position + 1);
	g_shell_env.paperweight.length = ft_strlen(g_shell_env.paperweight.buff);
	g_shell_env.paperweight.max = g_shell_env.paperweight.length;
	while (cursor->position != og_pos)
	{
		ft_delete(-1);
		og_pos--;
	}
}
