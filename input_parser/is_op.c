/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:15:15 by satkins           #+#    #+#             */
/*   Updated: 2018/04/04 18:18:44 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "ast.h"

int 				is_op(t_parser *par, char cur_char)
{
	if (!par->quoted && par->current_type == operator)
	{
		if (is_op_append(par->current_token, cur_char))
		{
			if (!(par->current_token = strappend(&(par->current_token), cur_char)))
				return (0);
			return (USED_CHAR);
		}
		else
		{
			if (add_token(par->current_token, &(par->current_type),
			par) == EXIT_FAILURE)
				return (0);
			return (CONTINUE);
		}
	}
	return (UNUSED_CHAR);
}

int 				is_start_op(t_parser *par, char cur_char)
{
	if (!par->quoted && is_op_append("", cur_char))
	{
		if (add_token(par->current_token, &(par->current_type), par) == EXIT_FAILURE
			|| !strappend(&(par->current_token), cur_char))
			return (0);
		par->current_type = operator;
		return (USED_CHAR);
	}
	return (UNUSED_CHAR);
}
