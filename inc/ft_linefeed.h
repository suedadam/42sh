/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linefeed.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:29:22 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 12:14:38 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINEFEED_H
# define FT_LINEFEED_H

# include "ft_term.h"

/*
**	pass off all buffer to lexer, ast creation and execution
**	(linefeed.c)
*/

int		ft_linefeed(void);

/*
**	quote mode handling on linefeed
**	(quote_mode.c)
*/

int		quote_mode(void);

#endif
