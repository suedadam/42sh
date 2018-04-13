/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:27:28 by asyed             #+#    #+#             */
/*   Updated: 2018/04/13 14:53:29 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

// void	itterate_pipes(t_ast *curr, t_ast **end)
// {
// 	if (*(curr->type) == OPERATOR && !strcmp(*(curr->token), "|"))
// 	{
// 		create_monitor(curr);
// 		// if (!curr->right_child || *(curr->right_child->type) != OPERATOR)
// 		// {
// 		// 	*end = curr->right_child;
// 		// 	run_operation(curr->right_child, 0);
// 		// 	printf("Need to run \"%s\"\n", *((*end)->token));
// 		// 	return ;
// 		// }
// 		// *end = curr->left_child;
// 		// itterate_pipes(curr->right_child, end);
// 		// run_operation(curr->left_child, 0);
// 	}
// 	printf("Should've never gotten here....\n");
// }

int		op_pipe_exec(t_ast *curr)
{
	// t_ast	*end;

	if (!curr)
		return (EXIT_FAILURE);
	create_monitor(NULL, curr);
	// itterate_pipes(curr, &end);
	// run_operation(curr->left_child, 0);
	// printf("End = \"%s\"\n", *(end->token));
	// if (end)
	// 	run_tree(end);
	// run_operation(curr->left_child, 0);
	// if (curr->right_child)
	// {
	// 	printf("Running operation on \"%s\"\n", *(curr->right_child->token));
	// 	run_operation(curr->right_child, 0);
	// 	run_tree(curr->right_child);
	// }
	return (EXIT_SUCCESS);
}
