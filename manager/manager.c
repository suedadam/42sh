/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:56:05 by asyed             #+#    #+#             */
/*   Updated: 2018/04/04 17:34:34 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
** Only builtins are ever going to require persistent modifications
** ToDo:
** 	Commands within a subshell we can run with a non-persistence flag
** 	that carries through to the execution function. 
**
** Free input_str after parser().
*/

int	manager(char *input_str)
{
	t_ast __attribute__ ((unused))		*res;
	void  __attribute__ ((unused))		*ast;

	if (!input_str)
		return (EXIT_FAILURE);
	// if (!(res = parser(input_str)))
	// {
	// 	free(input_str);
	// 	return (EXIT_FAILURE);
	// }
	// res->left_child = NULL;
	// res->right_child = NULL;
	// free(input_str);
	// if (!(ast = build_forest(res)))
	// 	;
	return (EXIT_SUCCESS);
}