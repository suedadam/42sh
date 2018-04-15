/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:02:51 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/14 19:43:54 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"

#define NO_CHILD -42

static int		next_child(t_trie *trie, int start)
{
	int		i;

	i = start + 1;
	if (trie->nbr_children)
		return (NO_CHILD);
	while (i < 128)
	{
		if (trie->children[i])
			return (i);
		i++;
	}
	return (NO_CHILD);
}

static void	one_child(t_trie *trie)
{
	int		child;

	child = next_child(trie, 0);
	regular_text(trie->key);
	trie_dfs(trie->children[child]);
}

static void	bottleneck(t_trie *trie, t_stack *stack)
{
	int			child;
	t_cursor	*cursor;

	if (isempty_stack(stack) || stack->top->content != trie)
	{
		regular_text(trie->key);
		ft_stackpush(stack, trie, sizeof(t_trie_with_level));
		cursor = g_shell_env.cursor;
		((t_trie_with_level *)(trie))->pos = cursor->position;
		((t_trie_with_level *)(trie))->child = 0;
		trie_dfs(trie);
	}
	else if ((child = next_child(trie, (int)(((t_trie_with_level *)(trie))->child))) != NO_CHILD)
	{
		((t_trie_with_level *)(trie))->child = child;
		trie_dfs(trie->children[child]);
	}
	else if (child == NO_CHILD)
	{
		free(ft_stackpop(stack));
		trie_dfs((t_trie *)((stack)->top->content));
	}
}

static void			resume_dfs(t_trie *trie)
{
	t_cursor			*cursor;

	cursor = g_shell.cursor;
	while (cursor->position != ((t_trie_with_level)(trie))->pos)
		ft_delete(-1);
	trie_dfs(trie);
}

void				trie_dfs(t_trie *trie, t_stack *stack)
{
	if (!trie && isempty_stack(stack))
		return ;
	else if (!trie)
		resume_dfs((t_trie *)(stack->top->content));
	if (trie->nbr_children == 1)
		one_child(trie);
	else if (trie->nbr_children > 1)
		bottleneck(trie, stack);
	else if (trie->nbr_children == 0)
		regular_text(trie->key);
}
