/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:15:19 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/11 15:52:38 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast		*new_ast_node(char **tokens, t_token_type *types,
	t_ast *left, t_ast *right)
{
	t_ast		*node;

	if (!(node = (t_ast *)ft_memalloc(sizeof(t_ast))))
		return (NULL);
	node->token = tokens;
	node->type = types;
	node->left_child = left;
	node->right_child = right;
	return (node);
}

t_ast		*new_ast_leaf(char **tokens, t_token_type *type)
{
	return (new_ast_node(tokens, type, NULL, NULL));
}
