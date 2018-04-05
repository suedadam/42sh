/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:11:39 by satkins           #+#    #+#             */
/*   Updated: 2018/04/04 19:38:34 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

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
		free(parser->tokens);
		free(parser);
		return (NULL);
	}
	if (!(parser->types = malloc(sizeof(t_token_type))))
	{
		free(parser->tokens);
		free(parser->current_token);
		free(parser);
		return (NULL);
	}
	parser->types = NULL;
	parser->current_type = null;
	parser->quoted = 0;
	return (parser);
}

t_ast				*parser(char *input_str)
{
	t_parser		*par;
	int				ret;

	if (!(par = init_parser()))
		return (NULL);
	while (*input_str)
	{
		ret = UNUSED_CHAR;
		if (!(ret = is_semi(par, *input_str)) ||
			(ret == UNUSED_CHAR && !(ret = is_op(par, *input_str))) ||
			(ret == UNUSED_CHAR && !(ret = is_quote(par, *input_str))) ||
			(ret == UNUSED_CHAR && !(ret = is_start_op(par, *input_str))) ||
			(ret == UNUSED_CHAR && !(ret = is_whitespc(par, &input_str))) ||
			(ret == UNUSED_CHAR && !(ret = is_word(par, *input_str))) ||
			(ret == UNUSED_CHAR && !(ret = is_comment(par, *input_str))) ||
			(ret == UNUSED_CHAR && !(ret = start_word(par, *input_str))))
		{
			free(par->current_token);
			free(par->tokens);
			free(par->types);
			free(par);
			return (NULL);
		}
		if (ret == CONTINUE)
			continue ;
		else if (ret == BREAK)
			break ;
		input_str++;
	}
	if (add_token(par->current_token, &(par->current_type), par) == EXIT_FAILURE)
	{
		free(par->current_token);
		free(par->tokens);
		free(par->types);
		free(par);
		return (NULL);
	}
	free(par->current_token);
	return ((t_ast *)par);
}

/*
**	int main(void)
**	{
**		parser("this is a final test \"in quotes \\\" \\t \" \'single quotes \\\" all good \' \\\" ");
**	}
*/
