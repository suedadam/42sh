/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:02:51 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/15 15:43:03 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"

#define NO_CHILD -42

static int		next_child(t_trie *trie, int start)
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

static void	one_child(t_trie *trie)
{
	int		child;

	child = next_child(trie, 0);
	printf("here |%c| child : [%d]\n", trie->key, child);
	regular_text(trie->key);
	trie_dfs(trie->children[child]);
}

static void	bottleneck(t_trie *trie, t_stack *stack)
{
	int			child;
	t_cursor	*cursor;

	if (!stack)
	{
		ft_printf("BONJOUR\n");
		exit(1);
	}
	if (!(stack->top) || ((t_trie *)(stack->top->content))->key != trie->key)
	{
		regular_text(trie->key);
		ft_stackpush(stack, trie, sizeof(t_trie_with_level));
		cursor = &g_shell_env.cursor;
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
		if ((t_trie *)((stack)->top))
			trie_dfs((t_trie *)((stack)->top->content));
	}
}

static void			resume_dfs(t_trie *trie)
{
	t_cursor			*cursor;

	cursor = &g_shell_env.cursor;
	while (cursor->position != ((t_trie_with_level *)(trie))->pos)
		ft_delete(-1);
	trie_dfs(trie);
}

void				trie_dfs(t_trie *trie)
{
	t_stack		*stack;

	ft_printf("here\n");
	stack = g_shell_env.cursor.wordloc == 1 ? g_shell_env.trie_binaries.stack
											: g_shell_env.trie_wdir.stack;
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
