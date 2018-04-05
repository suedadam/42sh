/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:04:38 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/04 20:53:18 by asyed            ###   ########.fr       */
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

/*
** ToDo:
** 	- Change token -> tokens (t_ast)
**	- Change type  -> types (t_ast)
*/

typedef struct				s_ast
{
	char					**token;
	t_token_type			*type;
	struct s_ast			*left_child;
	struct s_ast			*right_child;
}							t_ast;

typedef struct				s_parser
{
	char					**tokens;
	t_token_type			*types;
	char					*current_token;
	uint8_t					quoted;
	t_token_type			current_type;
}							t_parser;

int							is_op_append(char *token, char c);
char						*strappend(char **str, char c);
int							add_token(char *curr_token,
	t_token_type *curr_type, t_parser *par);
int							handle_embedded_quotes(uint8_t *quoted,
	char cur_char, char **current_token);
uint8_t						quoted_flags(char c);
void						print_toks(char **tokens, t_token_type *types);
int 						is_op(t_parser *par, char cur_char);
int 						is_semi(t_parser *par, char cur_char);
int 						is_quote(t_parser *par, char cur_char);
int 						is_start_op(t_parser *par, char cur_char);
int 						is_whitespc(t_parser *par, char **input_str);
int 						start_word(t_parser *par, char cur_char);
int 						is_comment(t_parser *par, char cur_char);
int 						is_word(t_parser *par, char cur_char);


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