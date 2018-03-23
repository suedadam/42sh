/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:16:12 by asyed             #+#    #+#             */
/*   Updated: 2018/03/23 00:05:34 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// t_ast	*build_standrd(void)
// {
// 	t_ast	*ast;

// 	if (!(ast = ft_memalloc(sizeof(t_ast))))
// 		return (NULL);
// 	if (!(ast->p_info = ft_memalloc(sizeof(t_process))))
// 	{
// 		free(ast);
// 		return (NULL);
// 	}
// 	ast->p_info->stdin = STDIN_FILENO;
// 	ast->p_info->stderr = STDERR_FILENO;
// 	if (!(ast->p_info->stdout = ft_memalloc(sizeof(int) * 2)))
// 	{
// 		free(ast);
// 		free(ast->p_info);
// 		return (NULL);
// 	}
// 	ast->p_info->stdout[0] = 1;
// 	ast->p_info->stdout[1] = 1;
// }

int		run_tree(t_ast *prev, t_ast *curr)
{
	if (prev)
	{
		if (*(prev->type) != operator)
		{
			printf("Error wtf why is it not an operator? Should've never gotten here....\n");
			return (-1);
		}
		if (!strcmp(*(prev->token), "|"))
		{
			printf("Pipe - carry over.\n");
			curr->stdin = prev->stdin;
		}
	}
	else
	{
		
	}
}

int		run_forest(t_ast **asts)
{
	int	i;

	i = 0;
	while (asts[i])
	{
		if (run_tree(NULL, asts[i]))
			return (-1);
		i++;
	}
}

// int	main(void)
// {
// 	int i;
// 	t_ast *test;

// 	i = 0;
// 	test = malloc(sizeof(t_ast));
// 	test->token = malloc(11 * sizeof(char *));
// 	test->type = malloc(11 * sizeof(enum token_type));
// 	while (i < 10)
// 	{
// 		if (i == 5)
// 		{
// 			test->token[4] = strdup("1");
// 			test->type[4] = token;
// 			test->token[5] = strdup(">>");
// 			test->type[5] = opp;

// 		}
// 		test->token[i] = strdup("what the hell dude");
// 		test->type[i] = token;
// 		i++;
// 	}
// 	callcmd(test);
// }