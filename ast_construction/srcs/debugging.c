/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:55:34 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/27 15:40:24 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdio.h>

static void	print_spaces(int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		ft_putstr(" ");
		j++;
	}
}

void		print_token(char **argv, t_token_type *types, int spaces)
{
	int i;

	i = 0;
	while (argv[i])
	{
		print_spaces(spaces);
		printf("token : [%s][%d]\n", argv[i], types[i]);
		i++;
	}
}

void		print_ast(t_ast *ast, int spaces)
{
	if (ast)
	{
		print_token(ast->token, ast->type, spaces);
		print_spaces(spaces);
		ft_putendl("   --> [left]");
		print_ast(ast->left_child, spaces + 4);
		print_spaces(spaces);
		ft_putendl("   --> [right]");
		print_ast(ast->right_child, spaces + 4);
		return ;
	}
}
