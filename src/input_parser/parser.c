
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
			meta_free(par->current_token);
		if (par->tokens)
		{
			i = 0;
			while (par->tokens[i])
				meta_free(par->tokens[i++]);
		}
		if (par->types)
			meta_free(par->types);
		meta_free(par);
	}
}

static inline __attribute__((always_inline)) void	*init_parser(void)
{
	t_parser	*parser;

	if (!(parser = ft_memalloc(sizeof(t_ast))))
		return (NULL);
	if (!(parser->tokens = ft_memalloc(sizeof(char *))))
	{
		meta_free(parser);
		return (NULL);
	}
	if (!(parser->current_token = ft_memalloc(sizeof(char) * 2)))
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
		// printf("%s -> %s\n", input_str, par->current_token);
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
	meta_free(par->current_token);
	return ((t_ast *)par);
}

// int main(int argc, char *argv[])
// {
// 	// t_ast	*ast;
// 	// int		i;

// 	// char *test_str = ;
// 	// ast = parser(test_str);
// 	// if (ast == MAP_FAILED)
// 	// 	ft_printf("SOFT FAILED ... LIKE Terrences dick\n");
// 	// else
// 	// {
// 	// 	i = 0;
// 	// 	while (ast->token[i])
// 	// 	{
// 	// 		ft_printf("%s (%d)\n", ast->token[i], ast->type[i]);
// 	// 		i++;
// 	// 	}
// 	// }
// 	manager(argv[1], NULL);
// 	return (0);
// }
