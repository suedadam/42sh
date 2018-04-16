/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_free_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:54:47 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/16 06:37:06 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdlib.h>

void		free_argv(char **argv)
{
	int i;

	i = 0;
	while (argv && argv[i])
	{
		meta_free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	meta_free(argv);
	argv = NULL;
}

void		free_types(t_token_type *types)
{
	meta_free(types);
	types = NULL;
}

void		free_ast(t_ast *ast)
{
	if (ast)
	{
		free_argv(ast->token);
		ast->token = NULL;
		free_types(ast->type);
		ast->type = NULL;
		if (ast->p_info)
		{
			free_process(ast->p_info);
			ast->p_info = NULL;
		}
		free_ast(ast->left_child);
		ast->p_info = NULL;
		free_ast(ast->right_child);
		ast->p_info = NULL;
		meta_free(ast);
		ast = NULL;
	}
}

void		free_forest(t_queue *forest)
{
	t_ast		*head;

	if (forest)
	{
		if (!(head = ft_dequeue(forest)))
			return ;
		free_ast(head);
		head = NULL;
		free_forest(forest);
	}
}
