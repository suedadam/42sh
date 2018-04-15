
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:11:39 by satkins           #+#    #+#             */
/*   Updated: 2018/04/12 00:27:46 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

inline __attribute__((always_inline)) void	free_segs(t_parser *par)
{
	int	i;

	if (par)
	{
		if (par->current_token)
			free(par->current_token);
		if (par->tokens)
		{
			i = 0;
			while (par->tokens[i])
				free(par->tokens[i++]);
		}
		if (par->types)
			free(par->types);
		free(par);
	}
}

static inline __attribute__((always_inline)) void	*init_parser(void)
{
	t_parser	*parser;

	if (!(parser = ft_memalloc(sizeof(t_ast))))
		return (NULL);
	if (!(parser->tokens = ft_memalloc(sizeof(char *))))
	{
		free(parser);
		return (NULL);
	}
	if (!(parser->current_token = ft_memalloc(sizeof(char))))
	{
		free_segs(parser);
		return (NULL);
	}
	if (!(parser->types = ft_memalloc(sizeof(t_token_type))))
	{
		free_segs(parser);
		return (NULL);
	}
	parser->types = NULL;
	parser->current_type = null;
	parser->quoted = 0;
	return (parser);
}

static int			check_char(t_parser **par, char **input_str)
{
	int				ret;

	ret = UNUSED_CHAR;
	if (!(ret = is_semi(*par, **input_str)) ||
		(ret == UNUSED_CHAR && !(ret = is_op(*par, **input_str))) ||
		(ret == UNUSED_CHAR && !(ret = quotes(*par, **input_str))) ||
		(ret == UNUSED_CHAR && (ret = is_command_sub(*par, input_str)) <= 0) ||
		(ret == UNUSED_CHAR && (ret = is_subshell(*par, input_str)) <= 0) ||
		(ret == UNUSED_CHAR && !(ret = is_start_op(*par, **input_str))) ||
		(ret == UNUSED_CHAR && !(ret = is_whitespc(*par, input_str))) ||
		(ret == UNUSED_CHAR && !(ret = is_word(*par, **input_str))) ||
		(ret == UNUSED_CHAR && !(ret = is_comment(*par, **input_str))) ||
		(ret == UNUSED_CHAR && !(ret = start_word(*par, **input_str))))
	{
		free_segs(*par);
		if (ret == EXIT_FAILURE_SOFT)
		{
			ft_printf("Parse Error\n");
			return (-1);
		}
		return (0);
	}
	return (ret);
}

t_ast				*parser(char *input_str)
{
	t_parser		*par;
	int				ret;
	int				paren;

	paren = 0;
	if (!input_str || !(par = init_parser()))
		return (NULL);
	while (*input_str)
	{
		// paren += check_paren(*input_str);
		if ((ret = check_char(&par, &input_str)) <= 0)
			return (ret == 0 ? NULL : MAP_FAILED);
		if (ret == CONTINUE)
			continue ;
		else if (ret == BREAK)
			break ;
		input_str++;
	}
	check_op_type(par);
	if (add_token(par->current_token, &(par->current_type), par)
		== EXIT_FAILURE)
	{
		free_segs(par);
		return (NULL);
	}
	if (paren || par->quoted)
		return (MAP_FAILED);
	free(par->current_token);
	// for (int j = 0; par->tokens[j]; j++)
	// 	ft_printf("%s\t[%d]\n", par->tokens[j], par->types[j]);
	return ((t_ast *)par);
}
