/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:02:17 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/16 00:54:32 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
#include "ft_proto.h"

char				*create_home_assoc(char *filename)
{
	char	*homepath;
	char	*temp;

	temp = __getenv("HOME", g_environ);
	homepath = concatpath("/", temp);
	homepath = concatpath(filename, homepath);
	return (homepath);
}

static void			history_append_list(char *buffer)
{
	t_hist_var		*history_var;

	history_var = &g_shell_env.history_var;
	if (buffer && history_var && history_var->history_list)
		dbl_push_front(history_var->history_list, buffer, ft_strlen(buffer) + 1);
}

void			free_dblist(t_dblist **delete)
{
	t_node	*temp;
	t_node	*nextemp;

	temp = (*delete)->first;
	while (temp != (*delete)->first && temp)
	{
		if (temp->content)
			meta_free(temp->content);
		nextemp = temp->next;
		meta_free(temp);
		temp = NULL;
		temp = nextemp;
	}
	meta_free(*delete);
	*delete = NULL;
}

int				delete_history(void)
{
	t_hist_var	*history_var;
	char		*histfile;
	int			i;

	history_var = &g_shell_env.history_var;
	i = 0;
	free_dblist(&history_var->history_list);
	history_var->history_list = new_dblist();
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
	t_hist_var	*history_var;
	t_node		*temp;
	int			i;

	history_var = &g_shell_env.history_var;
	temp = history_var->history_list->last;
	i = 0;
	while (temp && !(i && temp == history_var->history_list->last))
	{
		ft_printf_fd(STDIN_FILENO, "%d %s\n", i, (char *)(temp->content));
		temp = temp->previous;
		i++;
	}
	return (EXIT_SUCCESS);
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
	char			*histfile = NULL;
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
	histfile = NULL;
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
