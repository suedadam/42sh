/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:02:55 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/09 16:02:57 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CURSOR_H
#define FT_CURSOR_H

# include "ft_term.h"

/*
**	Single cursor movement commangs
**	(cursor_actions.c)
*/

void		cursor_to_right(t_cursor *cursor);
void		cursor_to_left(t_cursor *cursor);
void		cursor_to_home(t_cursor *cursor);
void		cursor_to_end(t_cursor *cursor);
void		cursor_to_left_margin(void);

/*
**	Cursor jump functions when invoked by ALT + {left, right, up, down}
**	(cursor_jump.c)
*/

void			jump_prev_word(t_cursor *cursor);
void			jump_next_word(t_cursor *cursor);
void			jump_next_line(t_cursor *cursor);
void			jump_prev_line(t_cursor *cursor);

/*
**	Cursor location for resizing window actions
**	(cursor_locate.c)
*/

void		cursor_locate(void);

/*
**	General move function for all cursor placement on the terminal
**	(cursor_move.c)
*/

void	move_cursor(t_cursor *cursor);

/*
**	Get the cursors first position, inmportant for anchoring all movement
**	across the lifetime of that line, relative to the cursor_buffer and
**	cursor_location reference
**	(cursor_position.c)
*/

void		get_cursor_first_position(void);


/*
**	Functions to hide the cursor as it moves
**	(cursor_visibility.c)
*/

void		invisible_cursor(void);
void		visible_cursor(void);

#endif
