/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:39:45 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/22 13:46:18 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static int			is_operator(char *token_char)
{
	return (str_search({"|", "&", "||", "&&", ";", NULL}, token_char));
}

static t_ast		*new_ast(void)
{
	if (!(ast = (t_ast *)ft_memalloc(sizeof(t_ast))))
		return (NULL);
	ast->token = 0;
	ast->type = 0;
	ast->left_child = 0;
	ast->right_child = 0;
	return (ast);
}

static t_ast		*build_ast(char **tokens, t_token_type *types, t_ast *ast)
{
	
}

static int			parse_tokens(char **tokens, t_token_type *type,
	t_list **forest)
{
	int		i;

	i = 0;
	while (tokens[i])
	{
		if (type[i] == operator && is_operator(tokens[i]))
		{
			build_forest()
			ft_lst()
			build_ast(strsub(0, i + 1), sub_token_type(type, 0, i + 1));
			parse_tokens(token + i, type + i);
		}
		i++;
	}
}

t_list				*build_forest(char **tokens, t_token_type *type)
{
	t_list		*forest;
	t_ast		*ast;

	if (!(forest = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
		t_ast		*ast;
	if (!(ast = new_ast()))
		return (NULL);

}
