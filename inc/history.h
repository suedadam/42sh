/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:02:15 by sgardner          #+#    #+#             */
/*   Updated: 2018/04/08 02:31:42 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H
# include "error.h"
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
# define GROWTH_PAD		150
# define HISTFILE		".shella_history"
# define HISTFILESIZE	0

# define HPOS(x, y, z)	((x + y) + z) % z

enum			e_histerr
{
	ERR_HIST_OOR
};

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
** history.c
*/

t_log			*hist_add(char *raw, int len);
void			hist_clear(void);
t_bool			hist_delete(int offset);
t_log			*hist_get(int offset);

/*
** history_io.c
*/

void			hist_load(char *path, t_hist *hist);
void			hist_save(char *path, t_hist *hist, int lines, t_bool append);

/*
** history_util.c
*/

void			hist_error(int errnum, void *param, t_bool isnum);
t_hist			*hist_getall(void);
void			hist_resize(t_hist *hist, int nsize);
#endif
