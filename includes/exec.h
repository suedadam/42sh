/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:38:25 by asyed             #+#    #+#             */
/*   Updated: 2018/03/29 16:51:11 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_EXEC_H
# define FT_EXEC_H
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "ast.h"
# define IS_REDIR(x) (x == '>' || x == '<' || x == ">>" || x == '<<')

typedef struct	s_process
{
	int		stdin;
	int		*comm; // 0 = read;1 = write
	int		*stdout; //0 = read;1 = write.
	int		stderr; // ^
	// int		*dep; // Need to build this in.
	uint8_t	ret;
}				t_process;

typedef struct	s_ophandlers
{
	int		(*check)(char *str);
	int		(*exec)(t_ast *curr);
}				t_ophandlers;

typedef struct	s_redir_op
{
	char	*opflag;
	int		(*func)(t_ast *test, size_t pos);
}				t_redir_op;

/*
** op_checks
*/

int		op_pipe_check(char *str);
int		op_or_check(char *str);
int		op_and_check(char *str);

/*
** op_execs
*/

int		op_pipe_exec(t_ast *curr);
int		op_or_exec(t_ast *curr);
int		op_and_exec(t_ast *curr);

/*
** execution.c
*/

int		run_operation(t_ast *curr, uint8_t wait);
void	build_leafs(t_ast *curr);
void	pipe_carry(t_ast *prev, t_ast *curr);
void	build_default(t_ast *curr);
int		build_info(t_ast *prev, t_ast *curr);
int		run_tree(t_ast *curr);

// int	run_forest(t_ast **asts);
// int	ops_redir_to(t_ast *curr, size_t pos);
// int	redir_outfile(t_process *p_info, t_ast *ast, size_t pos);
// int	redir_infile(t_process *p_info, t_ast *ast, size_t pos);

// extern struct s_redir_op	redir_ops[];
extern struct s_ophandlers	op_handlers[];

#endif