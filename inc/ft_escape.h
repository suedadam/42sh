/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:50:21 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 12:06:47 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ESCAPE_H
# define FT_ESCAPE_H

# include "ft_term.h"

# define ARROWS_LEFTRIGHT(x) (x == 67 || x == 68)
# define HOME_END_KEY(x) (x == 70 || x == 72)
# define DELETE_KEY(x) (x == 51)
# define SHIFTMOD(x) (x == 49)
# define PGKEYS(x) (x == 53 || x == 54)
# define ARROWS_UPDOWN(x) (x == 65 || x == 66)

/*
**	Alt key control capture and requisite dispatcher to action functions
**	(ft_alt.c)
*/

int		ft_alt(char byte);

/*
**	Backspace key capture and requisite dispatcher to action function
**	(ft_backspace.c)
*/

int		ft_backspace(void);

/*
**	Delete key capture and action, backspace is redirected here
**	(ft_backspace.c)
*/

void	delete_last(int starting_position, t_cursor *cursor);
int		ft_delete(char byte);

/*
**	History key capture, no action hooked up yet
**	(ft_history.c)
*/

int		ft_history(char byte);

/*
**	Linemove, capture and dispatch
**	(ft_linemove.c)
*/

int		ft_linemove(char byte);

/*
**	PGUP and PGDWN, capture, no dispatch
**	(ft_page.c)
*/

int		ft_page(char byte);

/*
**	Shift key modifier capture, redirect to normal actions or nothing at all
**	(ft_shift.c)
*/

int		ft_shift(char byte);

/*
**	General multibyte kepress dispatch, inlined to key_handler
**	(multibyte_dispatch.c)
*/

int		multibyte_dispatch(char byte);

/*
**	If scrolling is ever added, here are some barebones functions to use
**	(screen_scroll.c)
*/

int		scroll_up(void);
int		scroll_down(void);
int		ft_scroll(char byte);

#endif
