/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_editing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:03:02 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/09 19:30:43 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EDITING_H
#define FT_EDITING_H

#include "ft_term.h"

#define PAPER g_shell_env.paperweight

/*
**	Used for cutting from the screen, buffer, and adding to the paperweight buff
**	(cut_line.c)
*/

void 			cut_line_after_cursor(void);
void 			cut_line_before_cursor(void);

/*
**	For removing words from the buffer	
**	(cut_word.c)
*/

void 			cut_word_before_cursor(void);

/*
**	For pasting from the paperweight buffer	to the line buff
**	(yank.c)
*/

void			yank(char *buffer);

#endif
