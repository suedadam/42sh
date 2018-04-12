/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 01:11:16 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/14 15:15:58 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue				*init_queue(void)
{
	t_queue			*node;

	node = (t_queue *)malloc(sizeof(t_queue));
	node->first = NULL;
	node->last = NULL;
	return (node);
}

void				ft_enqueue(t_queue *queue, void *content, size_t c_size)
{
	t_node			*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->content = ft_memalloc(c_size);
	node->content = ft_memmove(node->content, content, c_size);
	node->next = NULL;
	if (!queue->last)
	{
		queue->last = node;
		queue->first = node;
	}
	else
	{
		queue->last->next = node;
		node->previous = queue->last;
		queue->last = node;
	}
	return ;
}

void				*ft_dequeue(t_queue *queue)
{
	t_node			*tmp;

	tmp = queue->first;
	if (tmp)
	{
		queue->first = tmp->next;
		if (!tmp->next)
			queue->last = NULL;
		else
			tmp->previous = NULL;
		return (tmp->content);
	}
	return (NULL);
}

void				*peek_queue(t_queue *queue)
{
	if (queue->first == NULL)
		return (NULL);
	return (queue->first->content);
}

void				ft_queuepush(t_queue *queue, void *content, size_t c_size)
{
	t_node			*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->content = ft_memalloc(c_size);
	node->content = ft_memmove(node->content, content, c_size);
	if (!queue->last)
		queue->last = node;
	node->previous = NULL;
	node->next = queue->first;
	if (queue->first)
		queue->first->previous = node;
	queue->first = node;
}
