/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pathnames.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:38:21 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/13 16:07:58 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"
#include "ft_proto.h"

int		pass_names(int word)
{
	// made to use g_environ, for now placeholder with PATH from getenv
	DIR		*d_base;
	char	**mul_path;
	char	**basepath;
	int		i;

	i = 0;
	if (!(mul_path = gather_path(word, &basepath)))
		return (EXIT_FAILURE);
	while (mul_path[i])
	{
		if (!(d_base = opendir(mul_path[i++])))
			return (EXIT_FAILURE);
		buildir_names(d_base, basepath);
	}
	level = buildir(d_base, base);
	closedir(d_base);
}
