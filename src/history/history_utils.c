/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 02:37:57 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/16 04:10:37 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
#include "ft_proto.h"

char			*create_home_assoc(char *filename)
{
	char	*homepath;
	char	*temp;
	char	*freer;

	temp = ft_getenv("HOME", g_environ);
	homepath = concatpath("/", temp);
	freer = homepath;
	homepath = concatpath(filename, homepath);
	meta_free(freer);
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
	// if (!(history_var->history_list = new_dblist()))
	// {
	// 	printf("\ndblist fail\n");
	// 	return (EXIT_FAILURE);
	// }
	history_var->current_history_cmd = NULL;
	if (!(history_var->history_list = get_history()))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
