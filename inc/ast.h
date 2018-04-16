/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:04:38 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/15 15:34:40 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "libft.h"
# include <unistd.h>
# include <sys/mman.h>

# define IS_WHITESPACE(c) (c == '\n' || c == '\t' || c == ' ' || c == '\v' || c == '\f' || c == '\r')
/*
** quoted flags
*/
# define SINGLE_QUOTE 0x1
# define DOUBLE_QUOTE 0x2
# define BACKSLASH 0x4
# define COMMENT 0x8
# define ERROR_BIT 0x10

# define BACKT 96
# define IS_ESCAPED(c) (c == '\\' || c == '$' || c == BACKT)
# define DOLLAR_OFFSET 2
# define SUBSHELL_OFFSET 1

# define IS_QUOTE(c) (c == '\'' || c == '\"' || c == '\\') ? 1 : 0

# define IS_WHITESPACE(c) (c == '\n' || c == '\t' || c == ' ' || c == '\v' || c == '\f' || c == '\r')

# define UNUSED_CHAR 7
# define USED_CHAR 12
# define CONTINUE 42
# define BREAK 69

# define OPS 8
# define REDIR_LIMIT 4
static const char			*ops[ OPS ] = {"&", "&&", "||", "|", ";", "<", ">", ">>"};

# define EXIT_FAILURE_SOFT -1

typedef enum	e_token_type
{
	null,
	WORD,
	OPERATOR,
	REDIR,
	DAEMON
}				t_token_type;

typedef struct	s_ast
{
	char					**token;
	t_token_type			*type;
	struct s_ast			*left_child;
	struct s_ast			*right_child;
	struct s_process		*p_info;
}				t_ast;

typedef struct	s_environ
{
	size_t		size;
	char		**environ;
}				t_environ;

typedef struct				s_parser
{
	char					**tokens;
	t_token_type			*types;
	char					*current_token;
	uint8_t					quoted;
	t_token_type			current_type;
}							t_parser;

int							manager(char *input_str, char **substr);
char						*bquote_command(char **input_str);

void						free_segs(t_parser *par);
char						*sh_strcat(char **front, char *back);
void						check_op_type(t_parser *par);
int							is_subshell(t_parser *par, char **input_str);
int							is_command_sub(t_parser *par, char **input_str);
char						*literal_command(char **input_str, int i);
int							is_op_append(char *token, char c);
char						*strappend(char **str, char c);
int							add_token(char *curr_token,
	t_token_type *curr_type, t_parser *par);
int							handle_embedded_quotes(t_parser *par, char cur_char);
uint8_t						quoted_flags(char c);
void						print_toks(char **tokens, t_token_type *types);
int 						is_op(t_parser *par, char cur_char);
int 						is_semi(t_parser *par, char cur_char);
int 						quotes(t_parser *par, char cur_char);
int 						is_start_op(t_parser *par, char cur_char);
int 						is_whitespc(t_parser *par, char **input_str);
int 						start_word(t_parser *par, char cur_char);
int 						is_comment(t_parser *par, char cur_char);
int 						is_word(t_parser *par, char cur_char);
int							check_paren(char c);

/*
** parser
*/

t_ast				*parser(char *input_str);

/*
** lol remove me.
*/

int				run_forest(t_queue *forest, char **substr, t_environ *env);
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
void			free_forest(t_queue *forest);

extern	t_environ	*g_environ;

#endif
