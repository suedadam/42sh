/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:15:19 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/22 14:26:16 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast		*new_ast_node(char **tokens, t_token_type *types,
	t_ast *left, t_ast *right)
{
	int			i;
	t_ast		*node;

	if (!(node = (t_ast *)ft_memalloc(sizeof(t_ast))))
		return (NULL);
	node->token = tokens;
	node->type = type;
	node->left_child = left;
	node->right_child = right;
	return (ast);
}

t_ast		*new_ast_leaf(char **tokens, t_token_type *type)
{
	return (new_ast_node(tokens, type, NULL, NULL));
}
