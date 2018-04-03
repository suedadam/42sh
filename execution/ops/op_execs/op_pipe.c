/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:27:28 by asyed             #+#    #+#             */
/*   Updated: 2018/04/03 00:07:54 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		op_pipe_exec(t_ast *curr, t_environ *environ)
{
	run_operation(curr->left_child, 0, environ);
	if (curr->right_child)
	{
		run_operation(curr->right_child, 1, environ);
		run_tree(curr->right_child, environ);
	}
	return (EXIT_SUCCESS);
}
