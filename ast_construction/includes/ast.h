/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:04:38 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/22 14:27:35 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef enum			e_token_type
{
						token,
						operator

}						t_token_type;

typedef struct				s_ast
{
	char					**token;
	t_token_type			*type;
	struct s_ast			*left_child;
	struct s_ast			*right_child;
}							t_ast;

/*
***		 utils (mostly parsing)
*/

t_token_type	*sub_token_type(t_token_type *array, int index, int length);
char			**sub_token_char(char **array, int index, int length);
int				str_search(char **argv, char *str);

/*
***		ast construction
*/

t_ast		*new_ast_node(char **tokens, t_token_type *types,
		t_ast *left, t_ast *right);
t_ast		*new_ast_leaf(char **tokens, t_token_type *type);

#endif
