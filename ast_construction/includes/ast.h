/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:04:38 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/27 15:42:47 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "libft.h"
# include "queue.h"

typedef enum	e_token_type
{
	token,
	operator
}				t_token_type;

typedef struct	s_ast
{
	char					**token;
	t_token_type			*type;
	struct s_ast			*left_child;
	struct s_ast			*right_child;
}				t_ast;

t_queue			*build_forest(char **tokens, t_token_type *type);

/*
***		 utils (mostly parsing)
*/

t_token_type	*sub_token_type(t_token_type *array, int index, int length);
char			**sub_token_char(char **array, int index, int length);
int				str_search(char **argv, char *str);

/*
***		ast construction
*/

t_ast			*new_ast_node(char **tokens, t_token_type *types,
				t_ast *left, t_ast *right);
t_ast			*new_ast_leaf(char **tokens, t_token_type *type);

/*
***		ast debugging
*/

void			print_token(char **argv, t_token_type *types, int spaces);
void			print_ast(t_ast *ast, int spaces);

/*
***		free utils
*/

void			free_argv(char **argv);
void			free_types(t_token_type *types);
void			free_ast(t_ast *ast);

#endif
