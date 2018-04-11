/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hangingbyte.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:16:46 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 15:54:34 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANGINGBYTE_H
# define FT_HANGINGBYTE_H

# include "ft_term.h"

/*
**	For proper handling of hanging curlies
**	(curly_mode.c)
*/

void	curly_check(char byte);

/*
**	Catch for hanging chars that should wrap <", ', [, (, {>
**	(hanging_byte.c)
*/

void	hanging_byte(char byte);

/*
**	For proper handling of hanging parens
**	(paren_mode.c)
*/

void	paren_check(char byte);

/*
**	quote mode handling on linefeed
**	(quote_mode.c)
*/

int		quote_mode(void);

#endif
