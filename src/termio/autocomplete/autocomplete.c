/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:02:51 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/16 03:21:17 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"

#define NO_CHILD -42

int					next_child(t_trie *trie, int start)
{
	int		i;

	i = start + 1;
	if (!trie->nbr_children)
		return (NO_CHILD);
	while (i < 128)
	{
		if (trie->children[i])
			return (i);
		i++;
	}
	return (NO_CHILD);
}

static void			one_child(t_trie *trie)
{
	int		child;

	child = next_child(trie, 0);
	regular_text(trie->key);
	trie_dfs(trie->children[child]);
}

static void			bottleneck(t_trie *trie, t_stack *stack)
{
	int			child;

	if (!stack || !trie)
		return ;
	if (!(stack->top) || ((t_trie *)(stack->top->content))->pos != trie->pos)
	{
		regular_text(trie->key);
		trie->pos = g_shell_env.cursor.position;
		ft_stackpush(stack, trie, sizeof(t_trie));
		if (!trie->is_word)
			trie_dfs(trie);
		trie->is_word = 0;
	}
	else if ((child = next_child(trie, (int)(trie->child))) != NO_CHILD)
	{
		trie->child = child;
		trie_dfs(trie->children[child]);
	}
	else if (child == NO_CHILD)
	{
		meta_free(ft_stackpop(stack));
		if ((t_trie *)((stack)->top))
			trie_dfs((t_trie *)((stack)->top->content));
	}
}

static void			resume_dfs(t_trie *trie, t_stack *stack)
{
	t_cursor			*cursor;
	t_autocheck			*trie_inf;

	cursor = &g_shell_env.cursor;
	cursor->wordloc == 1 ? (trie_inf = &(g_shell_env.trie_binaries)) :
		(trie_inf = &(g_shell_env.trie_wdir));
	if (cursor->position < trie->pos)
		return ;
	while (trie->pos > 0 && cursor->position != trie->pos)
		ft_backspace();
	trie->is_word = 0;
	if (trie->nbr_children <= 1)
	{
		ft_stackpop(stack);
		trie_dfs(trie->children[next_child(trie, 0)]);
		return ;
	}
	trie_dfs(trie);
}

void				trie_dfs(t_trie *trie)
{
	t_stack		*stack;

	stack = g_shell_env.cursor.wordloc == 1 ? g_shell_env.trie_binaries.stack
											: g_shell_env.trie_wdir.stack;
	if (!trie && isempty_stack(stack))
		return ;
	else if (!trie)
		resume_dfs((t_trie *)(stack->top->content), stack);
	else if ((trie->is_word && trie->nbr_children) || trie->nbr_children > 1)
		bottleneck(trie, stack);
	else if (trie->nbr_children == 1)
		one_child(trie);
	else if (trie->nbr_children == 0)
		regular_text(trie->key);
}
