/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:29:49 by asyed             #+#    #+#             */
/*   Updated: 2018/04/07 15:28:59 by tle-huu-         ###   ########.fr       */
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
# include <limits.h>
# include <sys/ioctl.h>

# include "libft.h"
# include "ft_printf.h"

# define BUFF_SIZE 5
# define UNSET (void *)

# define PRINTABLE(c) (c >= 32 && c <= 126)
#define T_BSLASH (g_shell_env.tokens.bslash)
#define T_MPASS (g_shell_env.tokens.mpass)
#define T_QUOTE (g_shell_env.tokens.quote)
#define T_DQUOTE (g_shell_env.tokens.dquote)
#define T_DBLESC (g_shell_env.tokens.dblesc)

int					g_ft_errnum;

enum {
	CURSOR_MOVE,
	DEL_KEY,
	SHIFT,
	ALT,
	SCROLL,
	HISTORY,
	PAGE
};

enum {
	C_A,
	C_E,
	C_G,
	C_H,
	C_J,
	C_K,
	C_L,
	C_M,
	C_O,
	C_U,
	C_V,
	C_W,
	C_Y
};

enum {
	SYSERR,
	TERMGET,
	TGETN,
	TGETZ,
	TGETSTR
};

typedef struct	s_vertex
{
	int		x;
	int		y;
}				t_vertex;

typedef struct	s_cursor
{
	t_vertex		og_position;
	t_vertex		res_position;
	t_vertex		og_screen;
	size_t			position;
	char			*buffer;
	size_t			buffer_length;
}				t_cursor;

typedef struct	s_errstr
{
	int			err;
	char		*str;
	size_t		len;
}				t_errstr;

typedef struct		s_buffer
{
	char			*buff;
	size_t			length;
	size_t			max_size;
}					t_buffer;

typedef struct		s_tokens
{
	int				mpass;
	int				bslash;
	int				control_v;
	int				quote;
	int				dquote;
	int				dblesc;
}					t_tokens;

typedef	struct		s_terminf
{
	struct termios		original_tty; /* no free */
	struct termios		*shell_tty; /* FREE */
	struct winsize		window;
	t_buffer			*buffer;
	t_buffer			paperweight;
	t_cursor			cursor;
	t_tokens			tokens;
	// t_hashtable		*hashtable;
	size_t				prompt_length;
	char				*term_name; /* no free */
	char				*term_buff; /* FREE */
}					t_terminf;

//void				__attribute__((deprecated)) *ft_memalloc(size_t size);

//
// typedef struct		s_env
// {
// 	t_terminf		*terminfo;
// 	t_hashtable		*hashtable;
// 	char			**envron
// }					t_env;

/*
** main
*/

int		init_shellenv(void);

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
int		ft_passinput(void);

/*
**		dispatcher for interpreting escape sequence (multibyte_dispatch.c)
*/

int		multibyte_dispatch(char byte);
int		control_dispatch(char byte);


/*
**		read_loop
*/

int		ft_read_loop(void);


/*
**		prompt_utils
*/

int		new_prompt(char *prompt);
int		reset_prompt(void);
int		back_prompt(void);

/*
**		prompt_utils
*/
int		ft_linefeed(void);

/*
**		buffer_utils
*/
int			init_buffer(void);
int			reset_buffer(void);
int			resize_buffer(void);
int			reprint_buffer(void);


/*
**		keys_handler
*/

int				handle_keys(char byte);

/*
**		history
*/
int			add_buff_to_history(char *buffer);
int			open_history(void);

/*
**		cursor motions=
*/
void		move_cursor(t_cursor *cursor);
void		cursor_to_right(t_cursor *cursor);
void		cursor_to_left(t_cursor *cursor);
void		cursor_to_home(t_cursor *cursor);
void		cursor_to_end(t_cursor *cursor);
void		cursor_locate(void);

/*
**		cursor navigation
*/

void	jump_prev_word(t_cursor *cursor);
void	jump_next_word(t_cursor *cursor);
void	jump_next_line(t_cursor *cursor);
void	jump_prev_line(t_cursor *cursor);

/* ft_linemove */

int		ft_linemove(char byte);

/*
**		screen info
*/

int		get_window_size(void);

/*
**		utils
*/

void		get_cursor_first_position(void);

/*
**		utils
*/

int			control_c(void);
int			control_a(void);
int			control_y(void);
int			control_k(void);
int			control_e(void);
int			control_l(void);
int			control_newline(void);
int			control_g(void);
int			control_h(void);
int			control_j(void);
int			control_m(void);
int			control_o(void);
int			control_u(void);
int			control_v(void);
int			control_w(void);
int			ft_backspace(void);
int			ft_delete(char byte);

t_terminf	g_shell_env;

/*
**		backslash handler
*/
int		backslash_char(void);

/*
**		update screen utils
*/
void		update_end_of_screen(void);
void		update_buffer(char *buffer, int inc);
int			quote_mode(void);
void		relative_move_cursor(t_cursor *cursor);
int			scroll_up(void);
int			scroll_down(void);
void		__attribute__((deprecated)) resize_prompt(void);

void		invisible_cursor(void);
void		visible_cursor(void);

int			__attribute__((deprecated)) del_lines(void);

/*
**		initialize tokens
*/

int			__attribute__((deprecated)) count_lines(void);

/*
**		Advanced editing
*/
void			yank(char *buffer);
void 			cut_line_after_cursor(void);
void 			cut_line_before_cursor(void);
void 			cut_word_before_cursor(void);

void		get_cursor_current_position(void);

int		ft_shift(char byte);
int		ft_jumpwords(char byte);
int		ft_alt(char byte);
int		regular_text(char byte);
void	clear_below(void);
void	cursor_to_left_margin(void);
int		ft_scroll(char byte);
int		ft_history(char byte);
int		ft_page(char byte);

#endif
