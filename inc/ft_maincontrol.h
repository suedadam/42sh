/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maincontrol.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:16:03 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 12:08:54 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAINCONTROL_H
# define FT_MAINCONTROL_H

# include "ft_term.h"

/*
**	tty settings and resetting
**	(change_termial.c)
*/

int		ft_setty(void);
int		ft_restoretty(void);

/*
**	error handling, to be deprecated
**	(error.c)
*/

void	ft_terror(void);

/*
**	Function jump arrays
**	(jump_defs.c)
*/

int		(*g_multibyte_jump[7])(char byte);
int		(*g_control_jump[25])();

/*
**	Key handling, byte by byte, only strict ascii supported now
**	(key_handler.c)
*/

int		handle_keys(char byte);

/*
**	Does just what is says
**	(main.c)
*/

int		init_shellenv(void);

/*
**	Termcaps sucks
**	(my_putchar.c)
*/

int		my_putchar(int chrr);

/*
**	Reading loop and dispatchers to key handling functions
**	(read_loop.c)
*/

int		ft_read_loop(void);

/*
**	Regular printing, cursor and buffer movement
**	(regular_text.c)
*/

int		regular_text(char byte);

/*
**	Signal capture and handling redirects
**	(set_signal.c)
*/

int		shsignal_handlers(void);

#endif
