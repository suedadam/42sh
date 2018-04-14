/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:43:15 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/14 01:10:07 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIE_H
# define TRIE_H

# include "libft.h"

# define FOUND		42
# define NOT_FOUND	-42

typedef struct s_trie
{
	struct s_trie	*children[128];
	char			key;
	int				nbr_children;
}				t_trie;

void		add_word_to_trie(t_trie *trie, char *word);
t_trie		*new_trie(void);
int			search_word(t_trie *trie, char *word);
void		display_trie(t_trie *trie, int level);


#endif

{
	t_list		*gothrough;
	t_list		*node_list;
	t_node		*node;

	gothrough = parent->neighbors;
	while (gothrough)
	{
		node = graph->tab[((t_nghbr_node *)(gothrough->content))->index];
		if (node->dist < 0)
		{
			node->dist = dist + 1;
			node->parent = parent->index;
			node_list = ft_lstnew(node, sizeof(*node));
			enqueue(queue, node_list);
		}
		gothrough = gothrough->next;
	}
}

int				bfs(t_graph *graph, int start)
{
	t_queue		*queue;
	t_list		*tmp;
	t_node		*node;
	int			dist;

	queue = new_queue();
	dist = 0;
	graph->tab[start]->dist = dist;
	tmp = ft_lstnew(graph->tab[start], sizeof(*(graph->tab[start])));
	enqueue(queue, tmp);
	while (!queue_empty(queue))
	{
		tmp = queue_pop(queue);
		node = (t_node *)(tmp->content);
		gothrough_neighbors(graph, node, node->dist, queue);
		free(tmp->content);
		free(tmp);
	}
	free(queue);
	if (graph->tab[graph->start]->parent < 0)
	{
		ft_printf("\nBFS error\n");
		return (ERROR);
	}
	return (SUCCESS);
}
