/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:15:15 by satkins           #+#    #+#             */
/*   Updated: 2018/04/14 02:25:48 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	check_op_type(t_parser *par)
{
	int	i;
	if (!par || par->current_type != OPERATOR)
		return ;
	i = 0;
	while (i < OPS)
	{
		if (ft_strequ(ops[i], par->current_token))
			break ;
		i++;
	}
	if (i == 0)
		par->current_type = DAEMON;
	else if (i > REDIR_LIMIT)
		par->current_type = REDIR;
}

int	is_op(t_parser *par, char cur_char)
{
	if (!par->quoted && par->current_type == OPERATOR)
	{
		if (is_op_append(par->current_token, cur_char))
		{
			if (!(par->current_token =
				strappend(&(par->current_token), cur_char)))
				return (0);
			return (USED_CHAR);
		}
		else
		{
			check_op_type(par);
			if (add_token(par->current_token, &(par->current_type),
			par) == EXIT_FAILURE)
				return (0);
			return (CONTINUE);
		}
	}
	return (UNUSED_CHAR);
}

int	is_start_op(t_parser *par, char cur_char)
{
	if (!par->quoted && is_op_append("", cur_char))
	{
		if (add_token(par->current_token, &(par->current_type), par)
			== EXIT_FAILURE ||
			!strappend(&(par->current_token), cur_char))
			return (0);
		par->current_type = OPERATOR;
		return (USED_CHAR);
	}
	return (UNUSED_CHAR);
}
