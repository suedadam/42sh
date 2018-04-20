/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:47:47 by asyed             #+#    #+#             */
/*   Updated: 2018/04/16 08:28:05 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		op_and_exec(t_ast *curr, t_environ *env)
{
	if (!curr)
		return (EXIT_FAILURE);
	if (!run_operation(curr->left_child, 1, env))
	{
		run_operation(curr->right_child, 1, env);
		if (curr->right_child && *(curr->right_child->type) == OPERATOR)
			return (run_tree(curr->right_child, env));
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
