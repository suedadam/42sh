/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autofind_pathnames.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:58:55 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/13 22:10:15 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"
#include "ft_proto.h"

int		autofind_pathnames(void)
{
	DIR		*d_base;
	char	**mul_path;
	char	*basepath;
	int		i;
	int		word;

	i = 0;
	word = g_shell_env.cursor.wordloc;
	if (!(mul_path = gather_paths(word, &basepath)))
		return (EXIT_FAILURE);
	while (mul_path[i])
	{
		if (!(d_base = opendir(mul_path[i])))
			return (EXIT_FAILURE);
		if (word == 1)
			basepath = mul_path[i];
		buildir_names(d_base, basepath);
	}
	closedir(d_base);
	if (word > 1)
		free(basepath);
	del_paths(mul_path);
	return (EXIT_SUCCESS);
}
