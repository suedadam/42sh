/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2018/03/29 16:24:10 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H


# include <curses.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>

# include "libft.h"
# include "ft_printf.h"

# define LSEEK(x) ((x >=70 && x <= 72) || (x >= 'C' && x <= 'D'))
# define DEL(x) (x == 51)
# define SCRL(x) (x >= 53 && x <= 54)
# define HIST(x) (x >= 'A' && x <= 'B')
# define SHIFT(x)
# define BUFF_SIZE 1024

int					g_ft_errnum;

typedef struct	s_vertex
{
	int		x;
	int		y;
}				t_vertex;

typedef struct	s_cursor
{
	t_vertex	og_position;
	int			position;

}				t_cursor;

typedef struct	s_errstr
{
	int			err;
	char		*str;
	size_t		len;
}				t_errstr;

enum {
	SYSERR,
	TERMGET,
	TGETN,
	TGETZ,
	TGETSTR
};

enum {
	MOVE,
	DEL,
	SCROLL,
	HIST,
	SHIFT
};

enum {
	C_C,
	C_D,
	C_G,
	C_H,
	C_J,
	C_M,
	C_O,
	C_V,
	C_W
};

typedef struct		s_buffer
{
	char		*buff;
	int			length;
	int			max_size;
}					t_buffer;

typedef	struct		s_terminf
{
/* For ioctl purposes */
	struct termios		original_tty; /* no free */
	struct termios		*shell_tty; /* FREE */
/* For terminal initialization */
	char				*term_name; /* no free */
	char				*term_buff; /* FREE */
	int					prompt_length;
	t_buffer			*buffer;
	t_cursor			cursor;
	struct winsize		window;
	// t_hashtable		*hashtable;
}					t_terminf;


//
// typedef struct		s_env
// {
// 	t_terminf		*terminfo;
// 	t_hashtable		*hashtable;
// 	char			**envron
// }					t_env;


typedef struct		s_linebuf
{
	char			*line;
	char			*curr_pos;
	size_t			len;
}					t_linebuf;

/*
**		Error handling (error.c)
*/

void				ft_terror(void);

/*
**		Execution and tty handlers (exec_handlers.c)
*/

int		shsignal_handlers(void);
int		ft_setty(void);
int		ft_resetty(void);
int		ft_restoretty(void);

/*
**		ANSI sequences for cursor movement (cursor_moves.c)
*/

int		ft_curight(void);
int		ft_curleft(void);
int		ft_clearscreen(void);
void	ft_clearline(int clr);
int		ft_curhome(void);
int		my_putchar(int chrr);
int		ft_backspace(void);
int		ft_passinput(void);

/*
**		dispatcher for interpreting escape sequence (multibyte_dispatch.c)
*/

int		read_multibyte(char byte, int *mpass);
int		line_seek(t_terminf *anti, char byte);


/*
**		read_loop
*/

int		read_loop(void);


/*
**		prompt_utils
*/
void		new_prompt(void);

/*
**		prompt_utils
*/
int			ft_carriage_return(char byte, int slash_token);

/*
**		buffer_utils
*/
int			init_buffer();
int			handle_buffer();
int			resize_buffer();


/*
**		keys_handler
*/

int				handle_keys(char byte, int *mpass);

/*
**		history
*/
int			add_buff_to_history(char *buffer);
int			open_history();

/*
**		cursor motions=
*/
void		move_cursor(t_cursor *cursor);
void		cursor_to_right(t_cursor *cursor);
void		cursor_to_left(t_cursor *cursor);


t_terminf		g_shell_env;

#endif
