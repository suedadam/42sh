/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autofind_pathnames.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:58:55 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/15 10:25:34 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"
#include "ft_proto.h"

int		autofind_pathnames(void)
{
	DIR		*d_base;
	char	**mul_path;
	char	*temp;
	int		i;

printf("\nfinding pathnames\n");
	i = 0;
	if (!(mul_path = gather_paths(g_shell_env.cursor.wordloc)))
		return (EXIT_FAILURE);
	if (!mul_path[0])
	{
		printf("working dir\n");
		mul_path[0] = ".";
	}
	if (trie_rebuild(mul_path) == EXIT_SUCCESS)
	{
		while (mul_path[i])
		{
			printf("hello : [%s]\n", mul_path[i]);
			if (!(d_base = opendir(mul_path[i])))
			{
				i++;
				continue ;
			}
			temp = mul_path[i];
			buildir_names(d_base, temp);
			closedir(d_base);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
