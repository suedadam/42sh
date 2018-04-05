/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_free_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:54:47 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/04 21:50:54 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdlib.h>

void		free_argv(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void		free_types(t_token_type *types)
{
	free(types);
}

void		free_ast(t_ast *ast)
{
	if (ast)
	{
		free_argv(ast->token);
		free_types(ast->type);
		free_ast(ast->left_child);
		free_ast(ast->right_child);
	}
}
