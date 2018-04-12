/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:47:47 by asyed             #+#    #+#             */
/*   Updated: 2018/04/12 01:40:33 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		op_and_exec(t_ast *curr)
{
	if (!curr)
		return (EXIT_FAILURE);
	printf("&&L running operation \"%s\"\n", *(curr->left_child->token));
	if (!run_operation(curr->left_child, 1))
	{
		printf("&&R running operation \"%s\"\n", *(curr->right_child->token));
		run_operation(curr->right_child, 1);
		return (run_tree(curr->right_child));
	}
	else
		printf("&&L passed\n");
	return (EXIT_FAILURE);
}
