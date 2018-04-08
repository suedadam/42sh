/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:55:14 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/07 17:04:34 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"

int			new_prompt(char *prompt)
{
	char		*pwd;
	t_cursor	*cursor;
	size_t		length;
	int			n;

	if (get_window_size() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	cursor = &(g_shell_env.cursor);
	if (prompt)
	{
		length = g_shell_env.buffer->length;
		cursor->buffer += cursor->buffer_length;
		cursor->buffer_length = 0;
		n = ft_printf("%s", prompt);
	}
	else
	{
		if (!(pwd = getcwd(NULL, 0)))
		{
			g_ft_errnum = TERMGET;
			return (EXIT_FAILURE);
		}
		n = ft_printf("%s42sh %s[%s%s%s]%s %%%s ", BLU, GRN, RED, pwd, 
					GRN, YEL, NRM);
		g_shell_env.cursor.buffer_length = g_shell_env.buffer->length;
		cursor->buffer = g_shell_env.buffer->buff;
		free(pwd);
		pwd = NULL;
	}
	g_shell_env.prompt_length = n;
	cursor->position = 0;
	get_cursor_first_position();
	return (EXIT_SUCCESS);
}
