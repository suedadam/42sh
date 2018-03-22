/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:16:12 by asyed             #+#    #+#             */
/*   Updated: 2018/03/22 13:53:26 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct s_redir_op	redir_ops[] = {
	{">>", &redir_outfile},
	{"<<", &redir_infile},
	{NULL, NULL}
};

int	open_arg(char *str, t_process *p_info)
{
	if (*str == '&')
		symbolic_fd(str, t_process *p_info);
}

/*
** If 1 >> &2
*/

int	parse_redirection(t_ast *exec, t_process *p_info, size_t len)
{
	int i;
	char	*post;
	char	*prev;

	i = 0;
	prev = NULL;
	post = NULL;
	if (len > 0)
		prev = exec->token[len - 1];

	while (redir_ops[i].opflag)
	{
		if (!strcmp(redir_ops[i].opflag, exec->token[len]))
		{
			printf("Found it! \"%s\"\n", redir_ops[i].opflag);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	printf("\"%s\" Not found\n", exec->token[len]);
	return (EXIT_FAILURE);
}

t_process *init_process(void)
{
	t_process *info;

	if (!(info = malloc(sizeof(t_process))))
		return (NULL);
	if (!(info->stdout = malloc(sizeof(int) * 2)))
	{
		free(info);
		return (NULL);
	}
	if (!(info->stderr = malloc(sizeof(int) * 2)))
	{
		free(info);
		free(info->stdout);
		return (NULL);
	}
	info->stdin = 0; //How tf am I going to get this? We need a way to give me the previous one if there is one.
	if (pipe(info->stdout) == -1)
	{
		free(info);
		return (NULL);
	}
	if (pipe(info->stderr) == -1)
	{
		// close(info->stdout);
		free(info);
		return (NULL);
	}
	info->dep = NULL;
	return (info);
}

int	callcmd(t_ast *exec)
{
	char 		**argv;
	size_t		len;
	t_process	*p_info;
	size_t		i;

	len = 0;
	if (!(p_info = init_process()))
		return (EXIT_FAILURE);
	while (exec->token[len])
	{ 
		if (*(exec->type) == token)
			len++;
	}
	argv = malloc((len + 1) * sizeof(char *));
	len = 0;
	i = 0;
	while (exec->token[len])
	{
		if (*(exec->type) == token)
		{
			argv[i] = exec->token[len];
			i++;
		}
		else	
			parse_redirection(exec, p_info, len);
		len++;
	}
	printf("i = %zu and len = %zu\n", i, len);
	printf("Length = %zu\n", len);
	return (EXIT_SUCCESS);
}

int	main(void)
{
	int i;
	t_ast *test;

	i = 0;
	test = malloc(sizeof(t_ast));
	test->token = malloc(11 * sizeof(char *));
	test->type = malloc(11 * sizeof(enum token_type));
	while (i < 10)
	{
		if (i == 5)
		{
			test->token[4] = strdup("1");
			test->type[4] = token;
			test->token[5] = strdup(">>");
			test->type[5] = opp;

		}
		test->token[i] = strdup("what the hell dude");
		test->type[i] = token;
		i++;
	}
	callcmd(test);
}