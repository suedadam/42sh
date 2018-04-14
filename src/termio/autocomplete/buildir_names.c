/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildir_names.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:33:35 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/13 21:56:30 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"
#include "ft_proto.h"

int		buildir_names(DIR *d_base, char *basepath)
{
	struct dirent	*entry;
	struct stat		sbuf;
	char			*smallpath;
	char			*fullpath;

	while ((entry = readdir(d_base)))
	{
		smallpath = concatpath("/", basepath);
		fullpath = concatpath(entry->d_name, smallpath);
		if (lstat(fullpath, &sbuf) < 0)
			return (EXIT_FAILURE);
		id_add_name(&sbuf, entry);
		free(smallpath);
		free(fullpath);
	}
	return (EXIT_SUCCESS);
}
