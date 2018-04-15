/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:02:17 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/14 17:28:44 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

static void			history_append_list(char *buffer)
{
	t_hist_var		*history_var;

	history_var = &g_shell_env.history_var;
	if (buffer && history_var && history_var->history_list)
		dbl_push_front(history_var->history_list, buffer, ft_strlen(buffer));
}


static void		swap_buffer(char *buffer)
{
	t_cursor		*cursor;

	cursor = g_shell_env.cursor;
	cursor_to_home(cursor);
	while (cursor->position >= 0)
		ft_backspace();
	yank(buffer);
}

int				history_append_file(char *buffer)
{
	int		fd;

	if (!buffer)
		return (EXIT_FAILURE);
	if ((fd = open(HISTORY_FILE, O_CREAT | O_WRONLY)) < 0)
		return (EXIT_FAILURE);
	ft_putendl_fd(buffer, fd);
	history_append_list(buffer);
	if (close(fd) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_dblist		*get_history(void)
{
	int				fd;
	int				gnl_ret;
	char			*line;
	t_dblist		*history_list;

	history_list = new_dblist(void);
	line = NULL;
	if ((fd = open(HISTORY_FILE, O_RDONLY)) < 0)
		return (NULL);
	while ((gnl_ret = get_next_line(fd, &line)) > 0)
		dbl_push_front(history_list, line, ft_strlen(line));
	free(line);
	if (close(fd) < 0 || gnl_ret < 0)
		return (NULL);
	return (history_list);
}
