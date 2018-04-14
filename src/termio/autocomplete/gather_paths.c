/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:41:40 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/14 02:13:36 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"
#include "ft_proto.h"

char	**gather_paths(int word)
{
	char	**mul_path;
	char	*temp;

	mul_path = NULL;
	temp = NULL;
	if (word == 1)
	{
	// made to use g_environ, for now placeholder with PATH from getenv
		temp = "PATH";
		if (!(temp = getenv(temp)))
			return (NULL);
		if (!(mul_path = ft_strsplit(temp, ':')))
			return (NULL);
	}
	else
	{
		temp = check_possible_dir();
		if (!(mul_path = (char **)ft_memalloc(sizeof(char *) * 2)))
			return (NULL);
		if (temp)
			mul_path[0] = temp;
		else
			mul_path[0] = NULL;
	}
	/*
		if (!(mul_path[0] = (char *)ft_memalloc(2)))
		{
			del_paths(mul_path);
			return (NULL);
		}
		mul_path[0][0] = '.';
	}
	*/
	return (mul_path);
}
