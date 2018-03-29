/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:16:12 by asyed             #+#    #+#             */
/*   Updated: 2018/03/28 23:20:24 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>

struct s_redir_op	redir_ops[] = {
	{">", &ops_redir_to}
};

int		run_operation(t_ast *curr)
{
	int	pid;

	if (!curr || *(curr->type) == operator)
	{
		printf("%d || %d\n", !curr, *(curr->type) != operator);
		return (-1);
	}
	if ((pid = fork()) == -1)
	{
		printf("fork() = %s\n", strerror(errno));
		return (-1);
	}
	if (pid == 0)
	{
		printf("%s out = %d in = %d\n", *(curr->token), *(curr->p_info->stdout), curr->p_info->stdin);
		dup2(curr->p_info->stdin, STDIN_FILENO);
		dup2(*(curr->p_info->stdout), STDOUT_FILENO);
		dup2(curr->p_info->stderr, STDERR_FILENO);
		char str[1024];
		strcpy(str, "/nfs/2017/a/asyed/TestExec/");
		strcpy(str, *(curr->token));
		printf("str = \"%s\" args = \"%s\"\n", str, curr->token[1]);
		execvp(str, curr->token);
		printf("Failed!\n");
	}
	return (0);
}

void	build_leafs(t_ast *curr)
{
	t_process *info;

	printf("BUilding mah leafs\n");
	if (!(info = ft_memalloc(sizeof(t_process))))
		return ;
	info->stdin = curr->p_info->stdin;
	if (!(info->stdout = ft_memalloc(sizeof(int))))
		return ;
	*(info->stdout) = curr->p_info->comm[1];
	curr->left_child->p_info = info;
	if (!(info = ft_memalloc(sizeof(t_process))))
		return ;
	info->stdin = curr->p_info->comm[0];
	if (!(info->stdout = ft_memalloc(sizeof(int))))
		return ;
	*(info->stdout) = curr->p_info->stdout[1];
	curr->right_child->p_info = info;
	printf("Done building mah leafs\n");
}

void	pipe_carry(t_ast *prev, t_ast *curr)
{
	int fds[2];

	if (!curr)
	{
		printf("puta\n");
		return ;
	}
	if (!curr->p_info && !(curr->p_info = ft_memalloc(sizeof(t_process))))
		return ;
	if (!prev)
		curr->p_info->stdin = STDIN_FILENO;
	pipe(fds);
	curr->p_info->comm = ft_memalloc(sizeof(int) * 2);
	memcpy(curr->p_info->comm, fds, sizeof(int) * 2);
	pipe(fds);
	curr->p_info->stdout = ft_memalloc(sizeof(int) * 2);
	if (!(curr->right_child->right_child)) //Right child should *ALWAYS* be allocated
	{
		fds[0] = STDOUT_FILENO;
		fds[1] = STDOUT_FILENO;
	}
	memcpy(curr->p_info->stdout, fds, sizeof(int) * 2);
	if (curr->left_child && curr->right_child)
		build_leafs(curr);
}

void	build_default(t_ast *curr)
{
	t_process *info;

	if (!(info = ft_memalloc(sizeof(t_process))))
		return ;
	info->stdin = STDIN_FILENO;
	if (!(info->stdout = ft_memalloc(sizeof(int))))
	{
		free(info);
		return ;
	}
	*(info->stdout) = STDOUT_FILENO;
	info->stderr = STDERR_FILENO;
	curr->p_info = info;
}

/* 
** The program should read the AST operation node
** Left:
** 	-> stdin = ASTOP->stdin;
**	-> stdout = ASTOP->comm[1];
** Right:
**  -> stdin = ASTOP->comm[0];
**	-> stdout = ASTOP->stdout[1];
**
** Leafs communicate on single INT pointers a/k/a:
** 	-> stdout = curr->p_info->stdout[0];
*/

int		build_info(t_ast *prev, t_ast *curr)
{
	if (!curr)
		return (-1);
	if (*(curr->type) == operator && !strcmp(*(curr->token), "|"))
		pipe_carry(prev, curr);
	else if ((prev && *(prev->type) != operator && strcmp(*(prev->token), "|")))
	{
		printf("This should theoretically never get here...\n");
		// build_default(curr);
	}
	else if (!prev)
	{
		build_default(curr);
		run_operation(curr);
		printf("Just one command....\n");
	}
	build_info(curr, curr->right_child);
	return (0);
}

/*
** I honestly dunno if this is going to work.
*/

int		ops_redir_to(t_ast *curr, size_t pos)
{
	size_t	len;
	int		fdptr;

	if (!curr->token[pos + 1])
		return (-1);
	if (*(curr->token[pos + 1]) == '&')
	{
		if (!curr->token[pos + 1][1])
			return (-1);
		if (curr->token[pos + 1][1] == '1')
			fdptr = (curr->p_info->stdout)[1];
		else if (curr->token[pos + 1][1] == '2')
			fdptr = curr->p_info->stderr;
		else
		{
			printf("Err not supported FD: \"%c\"\n", curr->token[pos + 1][1]);
			return (-1);
		}
	}
	else
	{
		if ((fdptr = open(curr->token[pos + 1], O_CREAT | O_TRUNC | O_WRONLY)) == -1)
		{
			printf("Failed to open = \"%s\"\n", strerror(errno));
			return (-1);
		}
	}
	if (strlen(curr->token[pos - 1]) > 1)
	{
		printf("Previous is too long: %d\n", strlen(curr->token[pos - 1]));
		return (-1);
	}
	if (*(curr->token[pos - 1]) == '2')
		curr->p_info->stderr = fdptr;
	else
		*(curr->p_info->stdout) = fdptr;
	return (0);
}

int		run_tree(t_ast *curr)
{
	if (!curr || !curr->left_child)
		return (0);
	printf("Running operation for %s(%s) -> %s\n", *(curr->token), *(curr->left_child->token), *(curr->right_child->token));
	run_operation(curr->left_child);
	if (curr->right_child && *(curr->right_child->type) == operator)
	{
		run_tree(curr->right_child);
	}
	else
	{
		if (curr->right_child)
			printf("--------> Right_child type = %s (%s) -> %d (%s)\n", *(curr->token), *(curr->left_child->token), *(curr->right_child->type), *(curr->right_child->token));
		else
			printf("--------> Right child is (NULL)\n");
		printf("Running operation for %s(%s) -> %s\n", *(curr->token), *(curr->right_child->token), *(curr->right_child->token));
		run_operation(curr->right_child);
	}
	return (0);
}

int		run_forest(t_ast **asts)
{
	int	i;

	i = 0;
	while (asts[i])
	{
		printf("hmmm\n");
		if (build_info(NULL, asts[i]))
			return (-1);
		if (run_tree(asts[i]))
			return (-1);
		i++;
		return (255);
	}
	return (0);
}
