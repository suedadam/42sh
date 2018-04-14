/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:38:25 by asyed             #+#    #+#             */
/*   Updated: 2018/04/13 21:47:10 by asyed            ###   ########.fr       */
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

/*
** Parent has 2 INTs while leafs/childs have one.
** For 2 INTs:
** 	- 0 = read 1 = write.
*/

typedef struct	s_process
{
	int		*stdin;
	int		*comm;
	int		*stdout;
	int		*stderr;
}				t_process;

typedef struct	s_ophandlers
{
	int		(*check)(char *str);
	int		(*exec)(t_ast *curr);
}				t_ophandlers;

typedef struct	s_redir_op
{
	char	*opflag;
	int		(*func)(t_ast *curr, int pos);
}				t_redir_op;

typedef struct	s_builtins
{
	char	*name;
	int		(*exec)(char **argv);
}				t_builtins;

/*
** builtins
*/

int				builtin_handler(t_ast *curr);
int				builtin_env(char *argv[]);
int				builtin_setenv(char *argv[]);
int				builtin_unsetenv(char *argv[]);
int				builtin_cd(char *argv[]);

/*
** op_checks
*/

int				op_pipe_check(char *str);
int				op_or_check(char *str);
int				op_and_check(char *str);

/*
** op_execs
*/

int				op_pipe_exec(t_ast *curr);
int				op_or_exec(t_ast *curr);
int				op_and_exec(t_ast *curr);

/*
** execution.c
*/

int				run_pipecmds(t_stack *cmd, t_queue *pids);
int				create_monitor(t_ast *prev, t_ast *curr);
int				run_operation(t_ast *curr, uint8_t wait);
void			build_leafs(t_ast *curr);
void			pipe_carry(t_ast *prev, t_ast *curr);
void			build_default(t_ast *curr);
int				build_info(t_ast *prev, t_ast *curr);
int				run_tree(t_ast *curr);

/*
** redirection.c
*/

int				handle_redirection(t_ast *curr);
int				ops_redir_to(t_ast *curr, int pos);
int				ops_append_to(t_ast *curr, int pos);
int				ops_read_from(t_ast *curr, int pos);

extern struct s_ophandlers	op_handlers[];
extern struct s_history		*hist_buf;

#endif
