/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:46:41 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 15:11:11 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void 			cut_line_after_cursor(void)
{
	char		*buffer;
	t_cursor	*cursor;

	cursor = &g_shell_env.cursor;
	buffer = cursor->buffer;
	free(g_shell_env.paperweight.buff);
	g_shell_env.paperweight.buff = 0;
	g_shell_env.paperweight.buff = ft_strdup(buffer + cursor->position);
	g_shell_env.paperweight.length = ft_strlen(g_shell_env.paperweight.buff);
	g_shell_env.paperweight.max_size = g_shell_env.paperweight.length;
	while (g_shell_env.buffer->length != cursor->position)
		ft_delete(-1);
}

void 			cut_line_before_cursor(void)
{
	char		*buffer;
	t_cursor	*cursor;

	cursor = &g_shell_env.cursor;
	buffer = cursor->buffer;
	free(g_shell_env.paperweight.buff);
	g_shell_env.paperweight.buff = 0;
	g_shell_env.paperweight.buff = ft_strsub(buffer, 0, cursor->position + 1);
	g_shell_env.paperweight.length = ft_strlen(g_shell_env.paperweight.buff);
	g_shell_env.paperweight.max_size = g_shell_env.paperweight.length;
	while (cursor->position)
		ft_backspace();
}
