/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:02:15 by sgardner          #+#    #+#             */
/*   Updated: 2018/04/10 06:39:57 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H
# include "error.h"
# include "exec.h"
# include "ft_getopt.h"
# include "libft.h"

/*
** Command history is the raw input string, after history expansion
**  HISTSIZE     -> # in memory, default 500
**  HISTFILESIZE -> # in HISTFILE (trunctaed on save/load), default unlimited
**  HISTFILE     -> File to save/load history (startup/exit/cmd), default none
**    * If nonexistent or not writeable, history is not saved
**
**	By default, history command prints -16 elements
**
** NOTE: functions requesting an offset start at array index 0, so user-supplied
**  offsets must be decremented
*/

/*
** Temporary macros for environment
*/

# define HISTSIZE		500
# define GROWTH_PAD		125
# define HISTFILE		".shella_history"
# define HISTFILESIZE	0

# define HDEF_ERROR(x)	hist_error(-1, FALSE, x)
# define HPOS(x, y, z)	((x + y) + z) % z

typedef struct	s_histopt
{
	char		**args;
	char		*del;
	char		*save_target;
	char		io_mode;
	t_bool		clear;
}				t_histopt;

typedef struct	s_log
{
	char		*data;
	int			len;
	t_bool		saved;
}				t_log;

typedef struct	s_hist
{
	t_log		*arr;
	int			len;
	int			size;
	int			maxsize;
	int			head;
	int			tail;
}				t_hist;

/*
** builtin_history.c
*/

int				builtin_history(char **av, t_process *pinfo);

/*
** history.c
*/

t_log			*hist_add(char *raw, int len);
void			hist_clear(void);
t_bool			hist_delete(int offset);
t_log			*hist_get(int offset);
t_hist			*hist_getall(void);

/*
** history_io.c
*/

void			hist_load(char *path, t_hist *hist);
void			hist_print(int fd, int start, int len, t_bool rev);
void			hist_save(char *path, t_hist *hist, int lines, t_bool append);

/*
** history_util.c
*/

void			hist_error(int errnum, char *param, t_bool fatal);
char			*hist_get_prefix(t_hist *hist, int max);
void			hist_resize(t_hist *hist, int nsize);
t_hist			*hist_scale(t_hist *hist);
t_bool			param_atoi(char *arg, int *n);
#endif