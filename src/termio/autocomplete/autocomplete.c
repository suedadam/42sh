/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:02:51 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/13 18:02:19 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

#define NO_CHILD -42

/*
** Might be static in the future
*/
t_list		*g_trie_stack = NULL;

static int		is_bottleneck(t_trie *trie)
{
	return (!!trie->nbr_children);
}

static int		is_rope(t_trie *trie)
{
	return (trie->nbr_children == 1);
}

static void		push_children(t_trie *trie, t_list *stack)
{
	int		i;

	i = 127;
	while (i >= 0)
	{
		if (trie->array[i])
			ft_stackpush(stack, trie->array[i], sizeof(trie->array[i]));
		i--;
	}
}

static int		fill_buffer_with_rope(t_trie *trie)
{

}

static int		rope_child_index(t_trie *trie)
{
	int		i;

	i = 0;
	if (trie->nbr_children <= 0)
		return (NO_CHILD);
	while (trie->array[i])
	{
		if (trie->array[i])
			return (i);
		i++;
	}
	return (NO_CHILD);
}

void				autocomplete_trie_dfs(t_trie *trie)
{
	static t_stack		*stack = new_stack();
	static int			length = 0;
	int					distance;
	t_trie				*head;

	distance = 0;
	while (!isempty_stack(stack))
	{

	}

}
