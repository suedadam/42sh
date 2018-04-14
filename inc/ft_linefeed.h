/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linefeed.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:29:22 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/14 12:44:56 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINEFEED_H
# define FT_LINEFEED_H

# include "ft_term.h"

/*
**	pass off all buffer to lexer, ast creation and execution
**	(linefeed.c)
*/
# define EXIT_FAILURE_SOFT -1

int		ft_linefeed(void);
int		manager(char *input_str, char **substr);

#endif
