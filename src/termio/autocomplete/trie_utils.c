/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:43:45 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/16 02:11:13 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"
#include "libft.h"

t_trie		*new_trie(void)
{
	t_trie		*trie;
	int			i;

	if (!(trie = ft_memalloc(sizeof(t_trie))))
		return (NULL);
	i = 0;
	while (i < 128)
	{
		trie->children[i] = NULL;
		i++;
	}
	trie->nbr_children = 0;
	trie->key = 0;
	trie->pos = -1;
	trie->child = 0;
	trie->is_word = 0;
	return (trie);
}

void		add_word_to_trie(t_trie *trie, char *word)
{
	t_trie		*nw_trie;

	if (trie && word)
	{
		if (!(*word))
		{
			trie->is_word = 1;
			return ;
		}
		if (trie->children[(int)(*word)])
			return (add_word_to_trie(trie->children[(int)(*word)], word + 1));
		trie->nbr_children++;
		nw_trie = new_trie();
		trie->children[(int)(*word)] = nw_trie;
		trie->children[(int)(*word)]->key = *word;
		return (add_word_to_trie(nw_trie, word + 1));
	}
}

int			search_word(t_trie *trie, char *word)
{
	if (trie && word)
	{
		if (!(*word))
			return (FOUND);
		else if (!(trie->children[(int)(*word)]))
			return (NOT_FOUND);
		else
			return (search_word(trie->children[(int)(*word)], word + 1));
	}
	return (NOT_FOUND);
}

void		display_trie(t_trie *trie, int level)
{
	int				i;

	i = 0;
	if (!trie || !trie->nbr_children)
		return ;
	ft_printf("-------\n");
	ft_printf("Level %d\n", level);
	while (i < 128)
	{
		if (trie->children[i])
			ft_printf("| %c ", (char)i);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < 128)
	{
		display_trie(trie->children[i], level + 1);
		i++;
	}
}

void		free_trie(t_trie *trie)
{
	int		i;

	if (trie)
	{
		i = 0;
		while (i < 128)
		{
			free_trie(trie->children[i]);
			i++;
		}
		meta_free(trie);
		trie = NULL;
	}
}
