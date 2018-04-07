/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:47:15 by sgardner          #+#    #+#             */
/*   Updated: 2018/04/06 17:11:14 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "libft.h"

# define NONFATAL			0
# define FATAL				!NONFATAL
# define FATAL_ERROR(x)		fatal_error(x)
# define DEFAULT_ERROR(x)	default_error(x)

/*
** error.c
*/

void	default_error(t_bool fatal);
void	fatal_error(const char *msg);
void	sh_error(const char *prefix, const char *err, const char *param);

extern char	*g_pname;
#endif
