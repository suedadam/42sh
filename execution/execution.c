/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:16:12 by asyed             #+#    #+#             */
/*   Updated: 2018/03/22 14:40:56 by asyed            ###   ########.fr       */
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

int		*create_fd(char *str)
{
	int	*fds;

	if (!(fds = malloc(sizeof(int) * 2)))
		return (NULL);
	if ((fds[0] = open(str, O_RDONLY)) == -1)
	{
		free(fds);
		return (NULL);
	}
	if ((fds[1] = open(str, O_WRONLY)) == -1)
	{
		free(fds);
		free(fds[0]);
		return (NULL);
	}
	return (fds);
}

int		*fd_pointer(char *str, t_process *p_info)
{
	int	rel_fd;

	if (*str == '&' || (strlen(str) == 1 && *str >= '0' && *str <= '2'))
	{
		str++;
		rel_fd = *str - '0';
		if (rel_fd == 1)
			return (p_info->stdout);
		if (rel_fd == 2)
			return (p_info->stderr);
		if (rel_fd == 0)
			return (p_info->stdin);
		return (NULL);
	}
	else
		return (create_fd(str));
}

int		open_arg(char *from, char *to, t_process *p_info)
{
	int	*from_p;

	if (!(from_p = fd_pointer(from, p_info)))
	{
		printf("Empty?\n");
		return (EXIT_FAILURE);
	}
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
	if (len > 0 && strlen(exec->token[len - 1] <= 2 ))
		prev = exec->token[len - 1];
	else
		prev = strdup("1"); /* Default to 1 if not explicity set. */
	if (exec->token[len] && exec->token[len + 1])
		post = exec->token[len + 1];
	else
	{
		printf("Error. Undefined behavior.\n");
		return (EXIT_FAILURE);
	}
	// open_arg(prev, post, p_info, 1);
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
	/*
	** I'll need to copy the stdin from the previous command if this is a pipe.
	*/
	if (!(info->stdin = malloc(sizeof(int) * 2)))
	{
		free(info);
		free(info->stdout);
		free(info->stderr);
		return (NULL);
	}
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