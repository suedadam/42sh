/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:47:15 by sgardner          #+#    #+#             */
/*   Updated: 2018/04/11 16:37:46 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "libft.h"
# include <errno.h>

# define FATAL_ERROR(x)	fatal_error(x)
# define DEFAULT_ERROR	default_error()

/*
** error.c
*/

void	default_error(void);
void	fatal_error(const char *msg);
void	sh_error(const char *prefix, const char *err, const char *param);

extern char	*g_pname;
#endif
