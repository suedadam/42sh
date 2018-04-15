/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:02:17 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/14 22:38:40 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
#include "ft_proto.h"

static void			history_append_list(char *buffer)
{
	t_hist_var		*history_var;

	history_var = &g_shell_env.history_var;
	if (buffer && history_var && history_var->history_list)
		dbl_push_front(history_var->history_list, buffer, ft_strlen(buffer) + 1);
}

int				history_init(void)
{
	t_hist_var	*history_var;

	history_var = &g_shell_env.history_var;
	if (!(history_var->history_list = new_dblist()))
	{
		printf("\ndblist fail\n");
		return (EXIT_FAILURE);
	}
	history_var->current_history_cmd = NULL;
	// if (!(history_var->current_history_cmd = new_node()))
	// {
	// 	printf("\ndblist fail\n");
	// 	return (EXIT_FAILURE);
	// }
	history_var->history_list = get_history();
	return (EXIT_SUCCESS);
}

int				history_append_file(char *buffer)
{
	int		fd;

	if (!buffer)
		return (EXIT_FAILURE);
	if ((fd = open(HISTORY_FILE, O_CREAT | O_APPEND | O_WRONLY, 0644)) < 0)
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

	history_list = new_dblist();
	line = NULL;
	fd = open(HISTORY_FILE, O_RDONLY | O_APPEND | O_CREAT, 0644);
	while ((gnl_ret = get_next_line(fd, &line)) > 0)
	{
		dbl_push_front(history_list, line, ft_strlen(line) + 1);
		free(line);
		line = NULL;
	}
	free(line);
	if (close(fd) < 0 || gnl_ret < 0)
		return (NULL);
	return (history_list);
}
