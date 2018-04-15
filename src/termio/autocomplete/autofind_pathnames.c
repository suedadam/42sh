/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autofind_pathnames.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:58:55 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/14 16:43:44 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"
#include "ft_proto.h"

int		autofind_pathnames(void)
{
	DIR		*d_base;
	char	**mul_path;
	char	*;
	int		i;

	i = 0;
	if (!(mul_path = gather_paths(g_shell_env.cursor.wordloc)))
		return (EXIT_FAILURE);
	if (!mul_path[0])
		mul_path[0] = ".";
	if (trie_rebuild(mul_path))
	{
		while (mul_path[i])
		{
			if (!(d_base = opendir(mul_path[i])))
				return (EXIT_FAILURE);
			if (word == 1)
				basepath = mul_path[i];
			buildir_names(d_base, basepath);
			closedir(d_base);
		}
	}
	return (EXIT_SUCCESS);
}
