/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:39:45 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/27 14:04:02 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdlib.h>

#define END_PARSING -1

static int			is_operator(char *token_char)
{
	int		res;
	int		i;
	char *operators[6];

	res = 0;
	operators[0] = ft_strdup("|");
	operators[1] = ft_strdup("&");
	operators[2] = ft_strdup("||");
	operators[3] = ft_strdup("&&");
	operators[4] = ft_strdup(";");
	operators[5] = NULL;
	res = str_search(operators, token_char);
	i = 0;
	while (operators[i])
	{
		if (operators[i])
		{
			free(operators[i]);
			operators[i] = NULL;
		}
		i++;
	}
	return (res);
}

static int			parse_tokens(char **tokens, t_token_type *type)
{
	int		i;

	i = 0;
	while (tokens[i])
	{
		if (type[i] == operator && is_operator(tokens[i]))
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
	if ((i = parse_tokens(tokens, type)) == END_PARSING)
		return (ast);
	*position += i + 1;
	sub_string = sub_token_char(tokens, 0, i + 1);
	sub_types = sub_token_type(type, 0, i + 1);
	if (ft_strequ(tokens[i], ";") || !tokens[i + 1])
		return (new_ast_leaf(sub_string, sub_types));
	ast = new_ast_node(sub_token_char(sub_string, i, 1),
			sub_token_type(sub_types, i, 1),
			new_ast_leaf(sub_token_char(sub_string, 0, i), sub_types),
			build_ast(tokens + i + 1, type + i + 1, position));
	free(sub_string);
	sub_string = NULL;
	return (ast);
}

t_queue				*build_forest(char **tokens, t_token_type *type)
{
	t_queue		*forest;
	t_list		*new_list;
	t_ast		*ast;
	int			pos;

	if (!(forest = new_queue()))
		return (NULL);
	pos = 0;
	while (tokens && type && (ast = build_ast(tokens + pos, type, &pos)))
	{
		new_list = ft_lstnew(ast, sizeof(*ast));
		enqueue(forest, new_list);
		free(ast);
	}
	return (forest);
}
