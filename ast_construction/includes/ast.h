/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:04:38 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/22 16:58:42 by satkins          ###   ########.fr       */
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



/*
** quoted flags
*/

# define SINGLE_QUOTE 1
# define DOUBLE_QUOTE 2
# define BACKSLASH 4
# define IS_QUOTE(c) (c == '\'' || c == '\"' || c == '\\' ? 1 : 0)
# define IS_WHITESPACE(c) (c == '\n' || c == '\t' || c == ' ' || c == '\v' || c == '\f' || c == '\r')
# define OPS 8
static const char			*ops[ OPS ] = {"&&", "||", ">>", ">", "&", "|", ">|", "<", "<<"};

#endif
