/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:41:40 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/16 02:11:33 by tle-huu-         ###   ########.fr       */
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
	return (mul_path);
}
