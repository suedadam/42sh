/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autocomplete.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:59:31 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/12 22:07:36 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AUTOCOMPLETE_H
# define FT_AUTOCOMPLETE_H

# include "ft_term.h"
# include "ft_proto.h"

/*
**	For finding relative word location / count on the terminal, which will
**	then dictate the type of trie that needs to be built
**	(count_word.c)
*/

void		wcount_forword(char byte);
void		wcount_backword(char byte);
void		find_backwords(void);

#endif
