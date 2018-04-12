/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:29:49 by asyed             #+#    #+#             */
/*   Updated: 2018/04/11 18:49:45 by asyed            ###   ########.fr       */
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
# include "error.h"

# define UNSET (void *)

# define IS_WHITESPACE(c) (c == '\n' || c == '\t' || c == ' ' || c == '\v'\
		|| c == '\f' || c == '\r')
# define PRINTABLE(c) (c >= 32 && c <= 126)
# define T_BSLASH (g_shell_env.tokens.bslash)
# define T_MPASS (g_shell_env.tokens.mpass)
# define T_QUOTE (g_shell_env.tokens.quote)
# define T_DQUOTE (g_shell_env.tokens.dquote)
# define T_DBLESC (g_shell_env.tokens.dblesc)
# define T_OPAREN (g_shell_env.tokens.oparen)
# define T_CPAREN (g_shell_env.tokens.cparen)
# define T_OCURLY (g_shell_env.tokens.ocurly)
# define T_CCURLY (g_shell_env.tokens.ccurly)
# define T_PIPE (g_shell_env.tokens.pipe)

int						g_ft_errnum;

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
	SYSERR = 1,
	TERMGET,
	TGETN,
	TGETZ,
	TGETSTR
};

typedef struct			s_vertex
{
	int					x;
	int					y;
}						t_vertex;

typedef struct			s_cursor
{
	t_vertex			og_position;
	t_vertex			res_position;
	t_vertex			og_screen;
	size_t				position;
	char				*buffer;
	size_t				buffer_length;
}						t_cursor;

typedef struct			s_errstr
{
	int					err;
	char				*str;
	size_t				len;
}						t_errstr;

typedef struct			s_buffer
{
	char				*buff;
	size_t				length;
	size_t				max_size;
}						t_buffer;

typedef struct			s_tokens
{
	int					mpass;
	int					control_v;
	int					quote;
	int					dquote;
	int					oparen;
	int					cparen;
	int					ocurly;
	int					ccurly;
	int					dblesc;
	int					pipe;
}						t_tokens;

typedef	struct			s_terminf
{
	struct termios		original_tty;
	struct termios		*shell_tty;
	struct winsize		window;
	t_buffer			*buffer;
	t_buffer			paperweight;
	t_cursor			cursor;
	t_tokens			tokens;
	size_t				prompt_length;
	char				*term_name;
	char				*term_buff;
}						t_terminf;

t_terminf				g_shell_env;

#endif
