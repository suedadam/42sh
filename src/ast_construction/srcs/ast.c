/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:39:45 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/17 21:17:11 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

#define END_PARSING -1

static int			parsing_pass(t_ast *ast)
{

	if (!ast)
		return (1);
	if (ast_is_leaf(ast))
		return (1);
	if (!(ast->left_child))
		return (0);
	if (ast->type[0] == OPERATOR && !(ast->left_child && ast->right_child))
		return (0);
	return (parsing_pass(ast->left_child) && parsing_pass(ast->right_child));
}

static int			parse_tokens(char **tokens, t_token_type *type)
{
	int		i;

	i = 0;
	while (tokens[i])
	{
		if (type[i] == OPERATOR)
			return (i);
		i++;
	}
	return (!i ? END_PARSING : i - 1);
}

static t_ast		*build_ast(char **tokens, t_token_type *type, int *position)
{
	t_ast				*ast;
	char				**sub_string;
	t_token_type		*sub_types;
	int					i;

	ast = NULL;
	i = 0;
	if ((i = parse_tokens(tokens, type)) == END_PARSING || (!i && *type == OPERATOR))
		return (ast);
	*position += i + 1;
	sub_string = sub_token_char(tokens, 0, i + 1);
	sub_types = sub_token_type(type, 0, i + 1);
	if (ft_strequ(tokens[i], ";") || !tokens[i + 1])
	{
		ft_strequ(tokens[i], ";") ? sub_string[i] = NULL : 0;
		return (new_ast_leaf(sub_string, sub_types));
	}
	ast = new_ast_node(sub_token_char(sub_string, i, 1),
			sub_token_type(sub_types, i, 1),
			new_ast_leaf(sub_token_char(sub_string, 0, i),
							sub_token_type(sub_types, 0, i)),
			build_ast(tokens + i + 1, type + i + 1, position));
	meta_free(sub_string);
	meta_free(sub_types);
	return (ast);
}

t_queue				*build_forest(char **tokens, t_token_type *type)
{
	t_queue		*forest;
	t_ast		*ast;
	int			pos;

	if (!(forest = new_queue()))
		return (NULL);
	pos = 0;
	while (tokens && type && (ast = build_ast(tokens + pos, type + pos, &pos)))
	{
		if (ft_enqueue(forest, ast, sizeof(t_ast)) == EXIT_FAILURE || !parsing_pass(ast))
		{
			errno = 8;
			free_forest(forest);
			return (NULL);
		}
		meta_free(ast);
	}
	if (isempty_queue(forest))
	{
		free_forest(forest);
		forest = NULL;
	}
	return (forest);
}
