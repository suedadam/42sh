/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_names.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:56:39 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/13 16:07:57 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"
#include "ft_proto.h"

char	**gather_path(int word, char **basepath)
{
	char	**mul_path;

	use = 0;
	if (word == 1)
		*basepath = "PATH";
	else
		*basepath = possible_dir();
	if (!(path = getenv(*basepath)))
		return (EXIT_FAILURE);
	if (word == 1)
	{
		if (!(mul_path = ft_strsplit(*basepath, ':')))
			return (NULL);
	}
	else
	{
//		if (!mul_path = 
	}
	return (mul_path);
}
