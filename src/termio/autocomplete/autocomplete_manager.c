/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 01:12:34 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/16 00:25:30 by nkouris          ###   ########.fr       */
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
	while ((counter > 0 && cursor->buffer[counter - 1] != '/') && (!IS_WHITESPACE(cursor->buffer[counter - 1])))
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
	// printf("advanced trie : bin <%p>, dir <%p>, <%p>\n", g_shell_env.trie_binaries.trie, g_shell_env.trie_wdir.trie, trie);
	// display_trie(trie, 0);

	// ft_printf("constructing the tree \n ---------------------------\n");
	// ft_printf("end constructing the tree \n ---------------------------\n");
	if (trie_toolbox->stack->top)
	{
		tputs(tgetstr("bl", 0), 1, my_putchar);
		trie_dfs(NULL);
	}
	else
	{
		tputs(tgetstr("vb", 0), 1, my_putchar);
		tmp_trie = advanced_trie(end_word_debut(), trie_toolbox->trie,
	 							trie_toolbox->stack);
		trie_dfs(tmp_trie);
	}
	// printf("done trie : <%p>\n", trie);
	// ft_printf("constructing the tree \n ---------------------------\n");
	// display_trie(trie, 0);
	// ft_printf("end constructing the tree \n ---------------------------\n");
	// exit(1);
	return (EXIT_SUCCESS);
}
