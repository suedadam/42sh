/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_linked_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:17:15 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/14 16:32:13 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dblist				*new_dblist(void)
{
	t_dblist			*node;

	if (!(node = (t_dblist *)ft_memalloc(sizeof(t_dblist))))
		return (NULL);
	node->first = NULL;
	node->last = NULL;
	return (node);
}

int					dbl_push_end(t_dblist *dblist, void *content, size_t c_size)
{
	t_node			*node;

	if (!dblist || !content ||
		!(node = (t_node *)ft_memalloc(sizeof(t_node))) ||
		!(node->content = ft_memalloc(c_size)))
		return (EXIT_FAILURE);
	node->content = ft_memmove(node->content, content, c_size);
	node->next = NULL;
	node->previous = NULL
	if (!dblist->last)
	{
		dblist->last = node;
		dblist->first = node;
	}
	else
	{
		dblist->last->next = node;
		node->previous = dblist->last;
		dblist->last = node;
	}
	return (EXIT_SUCCESS);
}

int					dbl_push_front(t_dblist *dblist, void *content, size_t c_size)
{
	t_node			*node;

	if (!dblist || !content ||
		!(node = (t_node *)ft_memalloc(sizeof(t_node))) ||
		!(node->content = ft_memalloc(c_size)))
		return (EXIT_FAILURE);
	node->content = ft_memmove(node->content, content, c_size);
	node->next = NULL;
	node->previous = NULL
	if (!dblist->last)
	{
		dblist->last = node;
		dblist->first = node;
	}
	else
	{
		node->next = dblist->first;
		dblist->first->previous = node;
		dblist->first = node;
	}
	return (EXIT_SUCCESS);
}

int					isempty_dblist(t_dblist *dblist)
{
	return (!dblist || !dblist->first);
}
