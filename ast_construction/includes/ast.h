/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:04:38 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/03 14:53:28 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

#include <stdlib.h>
#include "libft.h"
typedef enum			e_token_type	
{
						null,
						word,
						operator,
						redir

}						t_token_type;

typedef struct				s_ast
{
	char					**token;
	t_token_type			*type;
	struct s_ast			*left_child;
	struct s_ast			*right_child;
}							t_ast;

typedef struct				s_parser
{
	char					*current_token;
	char					**tokens;
	uint8_t					quoted;
	t_token_type			*types;
	t_token_type			current_type;
}							t_parser;

int							is_op(char *token, char c);
char						*strappend(char **str, char c);
int							add_token(char *curr_token,
	t_token_type *curr_type, char ***tokens , t_token_type **types);
int							handle_embedded_quotes(uint8_t *quoted,
	char **str, char **current_token);
uint8_t						quoted_flags(char c);
void						print_toks(char **tokens, t_token_type *types);

/*
** quoted flags
*/

# define SINGLE_QUOTE 1
# define DOUBLE_QUOTE 2
# define BACKSLASH 4
# define IS_QUOTE(c) (c == '\'' || c == '\"' || c == '\\' ? 1 : 0)

# define IS_WHITESPACE(c) (c == '\n' || c == '\t' || c == ' ' || c == '\v' || c == '\f' || c == '\r')

# define UNUSED_CHAR 7
# define USED_CHAR 12
# define CONTINUE 42
# define BREAK 69

# define OPS 9
static const char			*ops[ OPS ] = {"&&", "||", ">>", ">", "&", "|", ">|", "<", "<<"};

#endif
