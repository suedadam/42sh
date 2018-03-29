/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:47:47 by asyed             #+#    #+#             */
/*   Updated: 2018/03/29 16:49:09 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		op_or_exec(t_ast *curr)
{
	if (run_operation(curr->left_child, 1))
	{
		run_operation(curr->right_child, 1);
		return (run_tree(curr->right_child));
	}
	return (EXIT_FAILURE);
}
