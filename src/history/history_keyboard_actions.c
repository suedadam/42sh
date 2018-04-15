/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_keyboard_actions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:27:30 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/14 17:27:41 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void			up_history_command(void)
{
	t_hist_var		*history_var;

	history_var = &g_shell_env.history_var;
	if (isempty_dblist(history_var->history_list))
		return ;
	if (!history_var->current_history_cmd)
	{
		history_var->current_history_cmd = history_list->first;
		swap_buffer((char *)(history_list->first->content));
	}
	else
	{
		history_var->current_history_cmd = current_history_cmd->next;
		swap_buffer((char *)(history_list->first->content));
	}
}

void			down_history_command(void)
{
	t_hist_var		*history_var;

	history_var = &g_shell_env.history_var;
	if (isempty_dblist(history_var->history_list))
		return ;
	if (!history_var->current_history_cmd)
	{
		history_var->current_history_cmd = history_list->last;
		swap_buffer((char *)(history_list->first->content));
	}
	else
	{
		history_var->current_history_cmd = current_history_cmd->previous;
		swap_buffer((char *)(history_list->first->content));
	}
}
