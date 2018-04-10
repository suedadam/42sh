/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:02:37 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 14:25:19 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCREEN_H
# define FT_SCREEN_H

# include "ft_term.h"

/*
**	Clear all lines below line cursor is on
**	(clear_below.c)
*/

void	clear_below(void);

/*
**	Count lines, may be in use if screen scrolling is re-implemented
**	(count_lines.c)
*/

int		count_lines(void);

/*
**	Again, may be in use if screen scrolling is re-implemented
**	(del_lines.c)
*/

int		del_lines(void);

/*
**	Cursor og.screen values are useful for screen scrolling, if it's added
**	(get_window_size.c)
*/

int		get_window_size(void);

/*
**	Margins for the cursor
**	(Update_end_of_screen.c)
*/

void	update_end_of_screen(void);

#endif
