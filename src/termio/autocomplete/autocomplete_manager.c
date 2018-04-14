/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 01:12:34 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/14 02:12:34 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"

static char			*end_word_debut(void)
{
	char		*word;
	int			counter;
	t_cursor	*cursor;

	cursor = &g_shell_env.cursor;
	counter = cursor->position;
	while (counter > 0 && (!IS_WHITESPACE(cursor->buffer[counter - 1])) ||
	 	cursor->buffer[counter - 1] != '\0')
		counter--;
	word = cursor->buffer + counter;
	return (word);
}

static t_trie		*advanced_trie(char *word, t_trie *trie)
{
	if (IS_WHITESPACE(*word) || !(*word))
		return (trie);
	if (!trie->array[(int)(*word)])
		return (NULL);
	return (word + 1, trie->array[(int)(*word)]);
}

void				start_autocomplete(void)
{
	t_trie		*trie;

	if (update() || g_shell_env.trie == NULL)
		construct();
	trie = advanced_trie(end_word_debut(), g_shell_env.trie);
	if (trie)
		trie_dfs(trie, g_shell_env.tri_stack);
}
