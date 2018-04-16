/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_rebuild.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:28:14 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/16 02:12:19 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"
#include "ft_proto.h"
#include "trie.h"

static int	reinit_trie(t_autocheck *trie_inf)
{
	free_trie(trie_inf->trie);
	trie_inf->trie = NULL;
	if (!(trie_inf->trie = new_trie()))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			reinit_stack(t_autocheck *trie_inf)
{
	if (trie_inf)
		meta_free(trie_inf->stack);
	trie_inf->stack = NULL;
	if (!(trie_inf->stack = new_stack()))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	build_association(t_autocheck *trie_inf, char **mul_path)
{
	struct stat	sbuf;
	int			i;

	i = 0;
	reinit_trie(trie_inf);
	reinit_stack(trie_inf);
	while (mul_path[i++])
		trie_inf->nmem++;
	if (!(trie_inf->members = \
			(char **)ft_memalloc(sizeof(char *) * trie_inf->nmem)))
		return (-1);
	if (!(trie_inf->timestamp = \
			(time_t *)ft_memalloc(sizeof(time_t) * trie_inf->nmem)))
		return (-1);
	i = 0;
	while (mul_path[i])
	{
		trie_inf->members[i] = mul_path[i];
		if (lstat(mul_path[i], &sbuf) < 0)
			return (-1);
		trie_inf->timestamp[i] = sbuf.st_mtime;
		i++;
	}
	return (EXIT_SUCCESS);
}

int			trie_rebuild(char **mul_path)
{
	t_autocheck	*trie_inf;
	struct stat	sbuf;
	int			i;
	int			ret;

	g_shell_env.cursor.wordloc == 1 ? (trie_inf = &(g_shell_env.trie_binaries))
			: (trie_inf = &(g_shell_env.trie_wdir));
	i = 0;
	ret = EXIT_SUCCESS;
	while (trie_inf->members && trie_inf->timestamp && mul_path[i])
	{
		if (ft_strncmp(mul_path[i], trie_inf->members[i],
												ft_strlen(mul_path[i])))
			ret = EXIT_FAILURE;
		if (lstat(mul_path[i++], &sbuf) < 0)
			continue ;
		if (sbuf.st_mtime != trie_inf->timestamp[i])
			ret = EXIT_FAILURE;
		if (ret == EXIT_FAILURE)
			break ;
		i++;
	}
	if (!(trie_inf->members) || !(trie_inf->timestamp) || ret == EXIT_FAILURE)
		ret = build_association(trie_inf, mul_path);
	return (ret);
}
