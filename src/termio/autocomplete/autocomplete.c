/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 18:02:51 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/13 16:13:40 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

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

}

int				autocomplete_trie_dfs(t_trie *trie)
{
	static t_list		*stack = NULL;


}
