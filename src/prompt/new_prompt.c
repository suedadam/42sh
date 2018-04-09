/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:55:14 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/09 13:55:36 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"


static int		normal_prompt(void)
{
	char		*raw_pwd;
	char		*pwd;
	t_cursor	*cursor;
	int			offset;
	int			n;

	n = 0;
	cursor = &(g_shell_env.cursor);
	if (!(raw_pwd = getcwd(NULL, 0)))
	{
		g_ft_errnum = TERMGET;
		return (EXIT_FAILURE);
	}
	offset = ft_strstr(raw_pwd, getenv("HOME")) ? ft_strlen(getenv("HOME")) : 0;
	pwd = raw_pwd + offset;
	n = ft_printf("%s42sh %s[%s%c%s%s]%s %%%s ", CYN, GRN, MAG, offset ? '~' : 0
		, pwd, GRN, YEL, NRM);
	g_shell_env.cursor.buffer_length = g_shell_env.buffer->length;
	cursor->buffer = g_shell_env.buffer->buff;
	free(raw_pwd);
	raw_pwd = NULL;
	return (n);
}

static int		different_prompt(char *prompt)
{
	int			n;
	t_cursor	*cursor;

	cursor = &(g_shell_env.cursor);
	n = 0;
	if (prompt)
	{
		cursor->buffer += cursor->buffer_length;
		cursor->buffer_length = 0;
		n = ft_printf("%s%s%s", YEL, prompt, NRM);
	}
	return (n);
}

int				new_prompt(char *prompt)
{
	int			n;
	t_cursor	*cursor;

	cursor = &(g_shell_env.cursor);
	if (get_window_size() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (prompt)
		n = different_prompt(prompt);
	else
		n = normal_prompt();
	g_shell_env.prompt_length = n;
	cursor->position = 0;
	get_cursor_first_position();
	return (EXIT_SUCCESS);
}
