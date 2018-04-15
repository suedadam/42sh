/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildir_names.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:33:35 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/15 15:49:37 by nkouris          ###   ########.fr       */
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

	printf("I am entering build iddir\n");
	while ((entry = readdir(d_base)))
	{
		smallpath = concatpath("/", basepath);
		printf("smallpath <%s>\n", smallpath);
		fullpath = concatpath(entry->d_name, smallpath);
		printf("fullpath <%s>\n", fullpath);
		if (lstat(fullpath, &sbuf) < 0)
			return (EXIT_FAILURE);
		id_add_name(&sbuf, entry);
		meta_free(smallpath);
		meta_free(fullpath);
	printf("");	
	}
	return (EXIT_SUCCESS);
}
