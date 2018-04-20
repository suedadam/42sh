/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 01:12:34 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/16 02:13:29 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"

static t_trie		*advanced_trie(char *word, t_trie *trie, t_stack *stack)
{
	if (IS_WHITESPACE(*word) || !(*word))
	{
		if (trie->nbr_children == 1)
			return (trie->children[next_child(trie, 0)]);
		else if (trie->nbr_children == 0)
			return (NULL);
		trie->is_word = 0;
		if (g_shell_env.cursor.buffer[g_shell_env.cursor.position - 1] != '/')
			ft_backspace();
		return (trie);
	}
	if (!trie || !(trie->children[(int)(*word)]))
		return (NULL);
	return (advanced_trie(word + 1, trie->children[(int)(*word)], stack));
}

char				*end_word_debut(void)
{
	char		*word;
	int			counter;
	t_cursor	*cursor;

	cursor = &g_shell_env.cursor;
	counter = cursor->position;
	while ((counter > 0 && cursor->buffer[counter - 1] != '/')
				&& (!IS_WHITESPACE(cursor->buffer[counter - 1])))
		counter--;
	word = cursor->buffer + counter;
	return (word);
}

int					start_autocomplete(void)
{
	t_autocheck		*trie_toolbox;
	t_trie			*tmp_trie;

	if (!g_shell_env.cursor.position)
		return (EXIT_SUCCESS);
	find_backwords();
	if (autofind_pathnames() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	tmp_trie = NULL;
	g_shell_env.cursor.wordloc == 1 ?
					(trie_toolbox = &(g_shell_env.trie_binaries)) :
							(trie_toolbox = &(g_shell_env.trie_wdir));
	if (trie_toolbox->stack->top)
		trie_dfs(NULL);
	else
	{
		tmp_trie = advanced_trie(end_word_debut(), trie_toolbox->trie,
								trie_toolbox->stack);
		trie_dfs(tmp_trie);
	}
	return (EXIT_SUCCESS);
}
