/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 02:37:57 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/16 03:20:38 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
#include "ft_proto.h"

char			*create_home_assoc(char *filename)
{
	char	*homepath;
	char	*temp;

	temp = __getenv("HOME", g_environ);
	homepath = concatpath("/", temp);
	homepath = concatpath(filename, homepath);
	return (homepath);
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

int				history_init(void)
{
	t_hist_var	*history_var;

	history_var = &g_shell_env.hist_var;
	if (!(history_var->history_list = new_dblist()))
	{
		printf("\ndblist fail\n");
		return (EXIT_FAILURE);
	}
	history_var->current_history_cmd = NULL;
	history_var->history_list = get_history();
	return (EXIT_SUCCESS);
}
