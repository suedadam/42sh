/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:41:40 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/13 22:10:15 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"
#include "ft_proto.h"

char	**gather_paths(int word, char **basepath)
{
	char	**mul_path;

	mul_path = NULL;
	if (word == 1)
	{
	// made to use g_environ, for now placeholder with PATH from getenv
		*basepath = "PATH";
		if (!(*basepath = getenv(*basepath)))
			return (NULL);
		if (!(mul_path = ft_strsplit(*basepath, ':')))
			return (NULL);
	}
	else
	{
		*basepath = check_possible_dir();
		if (!(mul_path = (char **)ft_memalloc(sizeof(char *) * 2)))
			return (NULL);
		if (!(mul_path[0] = (char *)ft_memalloc(2)))
		{
			del_paths(mul_path);
			return (NULL);
		}
		mul_path[0][0] = '.';
	}
	return (mul_path);
}
