/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:02:17 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/16 03:26:16 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
#include "ft_proto.h"

static void		history_append_list(char *buf)
{
	t_hist_var		*hist_var;

	hist_var = &g_shell_env.hist_var;
	if (buf && hist_var && hist_var->history_list)
		dbl_push_front(hist_var->history_list, buf, ft_strlen(buf) + 1);
}

int				delete_history(void)
{
	t_hist_var	*hist_var;
	char		*histfile;
	int			i;

	hist_var = &g_shell_env.hist_var;
	i = 0;
	free_dblist(&hist_var->history_list);
	hist_var->history_list = new_dblist();
	histfile = create_home_assoc(HISTORY_FILE);
	if ((i = open(histfile, O_TRUNC) < 0))
	{
		meta_free(histfile);
		return (EXIT_FAILURE);
	}
	meta_free(histfile);
	if (close(i) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				display_history(void)
{
	t_hist_var	*hist_var;
	t_node		*temp;
	int			i;

	hist_var = &g_shell_env.hist_var;
	temp = hist_var->history_list->last;
	i = 0;
	while (temp && !(i && temp == hist_var->history_list->last))
	{
		ft_printf_fd(STDIN_FILENO, "%d %s\n", i, (char *)(temp->content));
		temp = temp->previous;
		i++;
	}
	return (EXIT_SUCCESS);
}

int				history_append_file(char *buffer)
{
	int		fd;
	char	*histfile;

	if (!buffer)
		return (EXIT_FAILURE);
	histfile = create_home_assoc(HISTORY_FILE);
	if ((fd = open(histfile, O_CREAT | O_APPEND | O_WRONLY, 0644)) < 0)
		return (EXIT_FAILURE);
	ft_putendl_fd(buffer, fd);
	history_append_list(buffer);
	meta_free(histfile);
	if (close(fd) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_dblist		*get_history(void)
{
	int				fd;
	int				gnl_ret;
	char			*line;
	char			*histfile;
	t_dblist		*history_list;

	history_list = new_dblist();
	line = NULL;
	histfile = create_home_assoc(HISTORY_FILE);
	if ((fd = open(histfile, O_RDONLY | O_APPEND | O_CREAT, 0644)) < 0)
	{
		meta_free(histfile);
		return (NULL);
	}
	meta_free(histfile);
	while ((gnl_ret = get_next_line(fd, &line)) > 0)
	{
		dbl_push_front(history_list, line, ft_strlen(line) + 1);
		meta_free(line);
		line = NULL;
	}
	meta_free(line);
	if (close(fd) < 0 || gnl_ret < 0)
		return (NULL);
	return (history_list);
}
