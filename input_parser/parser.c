/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:11:39 by satkins           #+#    #+#             */
/*   Updated: 2018/04/03 15:25:03 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdio.h>

static void 	skip_whitespace(char **input_str)
{
	if (!input_str)
		return ;
	while (IS_WHITESPACE(**input_str))
		(*input_str)++;
}

int					end_statement(char *curr_token, char ***tokens, t_token_type *current_type, t_token_type **types)
{
	t_token_type	tmp;

	tmp = operator;
	if (add_token(curr_token, current_type, tokens, types) == EXIT_FAILURE
		|| add_token(";", &tmp, tokens, types) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int			unquoted_conds(t_parser *par, char cur_char)
{
	int				ret;

	ret = USED_CHAR;
	if (cur_char == ';')
	{
		if (end_statement(par->current_token, &(par->tokens),
			&(par->current_type), &(par->types)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (par->current_type == operator)
	{
		if (is_op(par->current_token, cur_char))
		{
			if (!(par->current_token = strappend(&(par->current_token), cur_char)))
				return (EXIT_FAILURE);
		}
		else if (add_token(par->current_token, &(par->current_type),
			&(par->tokens), &(par->types)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		else
			return (CONTINUE);
	}
	else if (IS_QUOTE(cur_char))
		par->quoted = quoted_flags(cur_char);
	else
		ret = UNUSED_CHAR;
	return (ret);
}
static int			conds_extended(t_parser *par, char **input_str)
{
	if (IS_QUOTE(**input_str) || par->quoted & BACKSLASH)
	{
		if (handle_embedded_quotes(&(par->quoted), input_str, &(par->current_token)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (!par->quoted && is_op("", **input_str))
	{
		if (add_token(par->current_token, &(par->current_type), &(par->tokens), &(par->types)) == EXIT_FAILURE
			|| !strappend(&(par->current_token), **input_str))
			return (EXIT_FAILURE);
		par->current_type = operator;
	}
	else if (!par->quoted && IS_WHITESPACE(**input_str))
	{
		if (add_token(par->current_token, &(par->current_type), &(par->tokens), &(par->types)) == EXIT_FAILURE)
		 	return (EXIT_FAILURE);
		skip_whitespace(input_str);
		return (CONTINUE);
	}
	else if (par->current_type == word)
	{
		if (!(par->current_token = strappend(&(par->current_token), **input_str)))
			return (EXIT_FAILURE);
	}
	else if (**input_str == '#')
		return (BREAK);
	else
	{
		par->current_type = word;
		if (!(par->current_token = strappend(&(par->current_token), **input_str)))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
static inline __attribute__((always_inline)) void	*init_parser(void)
{
	t_parser	*parser;

	if (!(parser = malloc(sizeof(t_ast))))
		return (NULL);
	if (!(parser->tokens = malloc(sizeof(char *))))
	{
		free(parser);
		return (NULL);
	}
	if (!(parser->current_token = malloc(sizeof(char))))
	{
		free(parser);
		free(parser->tokens);
		return (NULL);
	}
	parser->types = NULL;
	parser->current_type = null;
	parser->quoted = 0;
	return (parser);
}

/*
** ToDo:
** When failing (return NULL) we need to free all memory regions
*/

t_ast				*parser(char *input_str)
{
	t_parser		*par;
	int				ret;

	if (!(par = init_parser()))
		return (NULL);
	while (*input_str)
	{
		ret = UNUSED_CHAR;
		if (!par->quoted && (ret = unquoted_conds(par, *input_str)) == EXIT_FAILURE)
			return (NULL);
		if (ret == UNUSED_CHAR && (ret = conds_extended(par, &input_str)) == EXIT_FAILURE)
			return (NULL);
		if (ret == CONTINUE)
			continue ;
		else if (ret == BREAK)
			break ;
		input_str++;
	}
	if (add_token(par->current_token, &(par->current_type), &(par->tokens), &(par->types)) == EXIT_FAILURE)
		return (NULL);
	print_toks(par->tokens, par->types);
	free(par->current_token);
	return ((t_ast *)par);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	parser(argv[1]);
}
