/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:04:52 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 12:14:44 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFER_H
# define FT_BUFFER_H

# include "ft_term.h"

/*
**	Buffer is initialized
**	(init_buffer.c)
*/

int			init_buffer(void);

/*
**	Buffer is reprinted
**	(reprint_buffer.c)
*/

int			reprint_buffer(void);

/*
**	Buffer is reset, meaning it is freed and re-initialized
**	(reset_buffer.c)
*/

int			reset_buffer(void);

/*
**	Buffer grows with max_size * 2
**	(resize_buffer.c)
*/

int			resize_buffer(void);

/*
**	Buffer is update with current byte
**	(resize_buffer.c)
*/

void		update_buffer(char *buffer, int inc);

#endif
