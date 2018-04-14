/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builders.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 22:46:16 by asyed             #+#    #+#             */
/*   Updated: 2018/04/14 11:57:17 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void		build_carry(t_ast *curr)
{
	t_process	*info;

	if (!curr || !(info = init_process()))
		return ;
	memcpy(info, curr, sizeof(t_process));
	curr->left_child->p_info = info;
}

/*
** Can probably take out parallel FDs.
** Change dereference to [0] here because its easier to read.
*/

void		build_leafs(t_ast *curr)
{
	t_process *info;

	if (!curr || !curr->left_child || !(info = init_process()))
		return ;
	*(info->stdin) = *(curr->p_info->stdin);
	info->stdin[1] = curr->p_info->stdin[1];
	*(info->stdout) = curr->p_info->comm[1];
	info->stdout[1] = curr->p_info->comm[0];
	*(info->stderr) = *(curr->p_info->stderr);
	info->stderr[1] = curr->p_info->stderr[1];
	curr->left_child->p_info = info;
	if (!curr->right_child || !(info = init_process()))
		return ;
	*(info->stdin) = curr->p_info->comm[0];
	info->stdin[1] = curr->p_info->comm[1];
	*(info->stdout) = curr->p_info->stdout[1];
	info->stdout[1] = curr->p_info->stdout[0];
	*(info->stderr) = *(curr->p_info->stderr);
	info->stderr[1] = curr->p_info->stderr[1];
	curr->right_child->p_info = info;
}

/*
** -> 1. This is only set when a pipe created it and the operator isn't a pipe.
**			This in turn needs to carry it over to the left leaf and reverse
**			execute and wait
*/

void	build_operator(__attribute__((unused))t_ast *prev, t_ast *curr)
{
	if (!curr)
		return ;
	if (curr->p_info)
	{
		build_carry(curr);
		build_default(curr->right_child);
		return ;
	}
	build_default(curr->left_child);
	build_default(curr->right_child);
}

void	build_default(t_ast *curr)
{
	t_process *info;

	if (!curr || *(curr->type) == OPERATOR)
		return ;
	if (!(info = init_process()))
		return ;
	*(info->stdin) = STDIN_FILENO;
	*(info->stdout) = STDOUT_FILENO;
	*(info->stderr) = STDERR_FILENO;
	curr->p_info = info;
}

/*
** The program should read the AST operation node
** Left:
** 	-> stdin = ASTOP->stdin;
**	-> stdout = ASTOP->comm[1];
** Right:
**  -> stdin = ASTOP->comm[0];
**	-> stdout = ASTOP->stdout[1];
**
** Leafs communicate on single INT pointers a/k/a:
** 	-> stdout = curr->p_info->stdout[0];
*/

int		build_info(t_ast *prev, t_ast *curr)
{
	if (!curr)
		return (EXIT_FAILURE);
	if (*(curr->type) == OPERATOR)
	{
		if (!strcmp(*(curr->token), "|"))
			pipe_carry(prev, curr);
		else
			build_operator(prev, curr);
	}
	else if (!prev)
	{
		build_default(curr);
		run_operation(curr, 1);
	}
	else
		build_info(curr, curr->right_child);
	return (EXIT_SUCCESS);
}
