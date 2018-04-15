/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 01:12:34 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/15 10:18:04 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"

static t_trie		*advanced_trie(char *word, t_trie *trie)
{
	printf("word : [%s]\n", word);
	if (IS_WHITESPACE(*word) || !(*word))
		return (trie);
	if (!(trie->children[(int)(*word)]))
		return (NULL);
	return (advanced_trie(word + 1, trie->children[(int)(*word)]));
}

char				*end_word_debut(void)
{
	char		*word;
	int			counter;
	t_cursor	*cursor;

	cursor = &g_shell_env.cursor;
	counter = cursor->position;
	while (counter > 0 && (!IS_WHITESPACE(cursor->buffer[counter - 1]) ||
	 	cursor->buffer[counter] == '\0'))
		counter--;
	word = cursor->buffer + counter;
	return (word);
}

int					start_autocomplete(void)
{
	t_trie		*trie;

	find_backwords();
	if (autofind_pathnames() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	g_shell_env.cursor.wordloc == 1 ? (trie = g_shell_env.trie_binaries.trie) :
		(trie = g_shell_env.trie_wdir.trie);
	printf("advanced trie : <%p>\n", trie);
	// display_trie(trie, 0);
	trie = advanced_trie(end_word_debut(), trie);
	printf("done trie : <%p>\n", trie);
	if (trie)
	{
		printf("before dfs\n");
		trie_dfs(trie);
		printf("after dfs\n");
	}
	return (EXIT_SUCCESS);
}
