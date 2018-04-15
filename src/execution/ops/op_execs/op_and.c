/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:47:47 by asyed             #+#    #+#             */
/*   Updated: 2018/04/14 17:45:01 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		op_and_exec(t_ast *curr, t_environ *env)
{
	if (!curr)
		return (EXIT_FAILURE);
	printf("&&L running operation \"%s\"\n", *(curr->left_child->token));
	if (!run_operation(curr->left_child, 1, env))
	{
		printf("&&R running operation \"%s\"\n", *(curr->right_child->token));
		run_operation(curr->right_child, 1, env);
		return (run_tree(curr->right_child, env));
	}
	else
		printf("&&L passed\n");
	return (EXIT_FAILURE);
}
