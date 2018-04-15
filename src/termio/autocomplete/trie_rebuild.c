/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_rebuild.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:28:14 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/14 17:06:24 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"

static int	build_association(t_autocheck *trie_inf, char **mul_path)
{
	struct stat	sbuf;

	while (mul_path[i++])
		trie_inf.nmem++;
	if (!(trie_inf->member = (char **)ft_memalloc(sizeof(char *) * trie_inf.nmem)))
		return (-1);
	if (!(trie_inf->timestamp = (time_t *)ft_memalloc(sizeof(time_t) * trie_inf.nmem)))
		return (-1);
	i = 0;
	while (mul_path[i])
	{
		trie_inf->member[i] = mul_path[i];
		if (lstat(mul_path[i], sbuf) < 0)
			return (-1);
		trie_inf->timestamp[i] = sbuf->st_mtime;
	}
}

int		trie_rebuild(char **mul_path)
{
	t_autocheck	trie_inf;
	struct stat	sbuf;
	int			i;
	int			ret;

	g_shell_cursor.wordloc == 1 ? trie_inf = g_shell_env.trie1 :
		trie_inf = g_shell_env.trie2;
	i = 0;
	while (trie_inf.members && trie_inf.timestamps && mul_path[i])
	{
		if (!ft_strncmp(mul_path[i], trie_inf.member[i], ft_strlen(mul_path[i])))
			ret = EXIT_FAILURE;
		if (lstat(mul_path[i], sbuf) < 0)
			return (-1);
		if (sbuf->st_mtime != trie_inf.timestamps[i])
			ret = EXIT_FAILURE;
		if (ret == EXIT_FAILURE)
			break ;
	}
	if (ret == EXIT_FAILURE)
		ret = build_association(&trie_inf, mul_path);
	return (ret);
}
