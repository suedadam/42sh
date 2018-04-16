/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 03:50:41 by asyed             #+#    #+#             */
/*   Updated: 2018/04/16 07:20:45 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_H
# define FT_EXEC_H
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
# include "ast.h"
# define IS_REDIR(x) (x == '>' || x == '<' || x == ">>" || x == '<<')

typedef struct	s_jobspec
{
	t_stack		*pids;
	char		*name;
}				t_jobspec;

typedef struct	s_ophandlers
{
	int		(*check)(char *str);
	int		(*exec)(t_ast *curr, t_environ *env);
}				t_ophandlers;

typedef struct	s_redir_op
{
	char	*opflag;
	int		(*func)(t_ast *curr, int pos);
}				t_redir_op;

typedef struct	s_builtins
{
	char	*name;
	int		(*exec)(char **argv, t_environ *env);
}				t_builtins;

/*
** job_control
*/

void			add_suspended(t_jobspec *job);
pid_t			unsuspend(char *name);
void			print_jobs(void);

/*
** utils
*/

void			*init_process(void);
int				compare(int *n1, int *n2);
int				fd_redir(t_ast *curr, int **src, int pos, uint8_t closer);

/*
** builders
*/

void			build_carry(t_ast *curr);
void			build_leafs(t_ast *curr);
void			build_operator(t_ast *curr);
void			build_default(t_ast *curr);
int				build_info(t_ast *prev, t_ast *curr);

/*
** builtins
*/

char			*ft_getenv(char *name, t_environ *env);
char			**ft_mutgetenv(char *name, t_environ *env);
int				builtin_handler(t_ast *curr, t_environ *env);
int				builtin_env(char *argv[], t_environ *env);
int				builtin_setenv(char *argv[], t_environ *env);
int				builtin_unsetenv(char *argv[], t_environ *env);
int				builtin_cd(char *argv[], t_environ *env);
int				builtin_echo(char *argv[], t_environ *env);
int				builtin_getenv(char *argv[], t_environ *env);
int				builtin_history(char *argv[], t_environ *env);
int				builtin_fg(char *argv[], t_environ *env);
int				builtin_bg(char *argv[], t_environ *env);
int				builtin_jobs(char *argv[], t_environ *env);
int				builtin_export(char *argv[], t_environ *env);
//int				builtin_exit(char *argv[], t_environ *env);

/*
** op_checks
*/

int				op_pipe_check(char *str);
int				op_or_check(char *str);
int				op_and_check(char *str);

/*
** op_execs
*/

int				op_pipe_exec(t_ast *curr, t_environ *env);
int				op_or_exec(t_ast *curr, t_environ *env);
int				op_and_exec(t_ast *curr, t_environ *env);

/*
** execution.c
*/

int				compare(int *n1, int *n2);
int				run_pipecmds(t_stack *cmd, t_pqueue *pids, t_environ *env);
int				run_operation(t_ast *curr, uint8_t wait, t_environ *env);
void			build_leafs(t_ast *curr);
void			pipe_carry(t_ast *prev, t_ast *curr);
void			build_default(t_ast *curr);
int				build_info(t_ast *prev, t_ast *curr);
int				run_tree(t_ast *curr, t_environ *env);

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
