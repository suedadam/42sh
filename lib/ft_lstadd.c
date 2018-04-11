/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 10:25:28 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/15 11:44:28 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_listcritpop(t_list **node, int (*f)(void *))
{
	t_list	*hold;
	t_list	*prev;

	hold = *node;
	prev = 0;
	while (hold)
	{
		if (f(hold->data))
		{
			if (hold == *node)
				*node = (*node)->next;
			else
				prev->next = hold->next;
			return (hold);
		}
		prev = hold;
		hold = hold->next;
	}
	return (0);
}

t_list	*ft_sublistpop(t_list **node, int (*f)(void *))
{
	t_list	*hold;
	t_list	*prev;
	t_list	*ret;

	hold = *node;
	prev = 0;
	ret = 0;
	while (hold)
	{
		if (f(hold->data))
		{
			if (hold == *node)
				*node = (*node)->next;
			else
				prev->next = hold->next;
			if (!ret)
				ret = hold;
			else
			{
				hold->next = ret;
				ret = hold;
			}
		}
		prev = hold;
		hold = hold->next;
	}
	return (ret ? ret : 0);
}

t_list	*ft_listpopfront(t_list **node)
{
	t_list	*hold;

	hold = *node;
	*node = (*node)->next;
	return (hold);
}

t_list	*ft_listnew(void *content, size_t content_size)
{
	t_list	*head;

	if (!(head = (t_list *)ft_memalloc(sizeof(t_list))))
		exit (0);
	if (!(head = (t_list *)ft_memalloc(sizeof(t_list)))
		|| !(head->data = ft_memalloc(content_size)))
		return (0);
	if (!content)
		content_size = 0;
	head->data = ft_memmove(head->data, content, content_size);
	head->d_size = content_size;
	return (head);
}

void	ft_listadd(t_list **alst, void *content, size_t content_size)
{
	t_list	*new;

	if (!*alst)
	{
		*alst = ft_listnew(content, content_size);
		return;
	}
	new = ft_listnew(content, content_size);
	new->next = *alst;
	*alst = new;
}
