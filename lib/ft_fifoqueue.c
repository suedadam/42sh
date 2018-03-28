/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fifoqueue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 09:41:27 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/13 09:44:37 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		Using a singly linked list, as defined in libft.h
**				|
**				first -> (next)
**				(next)
**				.
**				.
**				.
**				.
**				.
**				.	
**				last
**				|
*/

int			ft_ffenqueue(t_ffqueue **key, void *data, size_t size)
{
	t_list	*add;

	if (!(add = ft_listnew(data, size)))
		return (0);
	if (!(*key)->first)
		ft_ffpushfront(*key, add);
	else
		ft_ffpushend(*key, add);
	return (1);
}

void		ft_ffpushfront(t_ffqueue *key, t_list *data)
{
	t_list	*temp;

	if (key)
	{
		key->qlen++;
		if (!key->first)
		{
			key->first = data;
			key->last = data;
		}
		else
		{
			temp = key->first;
			data->next = temp;
			key->first = data;
		}
	}
}

void		ft_ffpushend(t_ffqueue *key, t_list *data)
{
	t_list	*temp;

	if (key)
	{
		key->qlen++;
		if (!key->last)
		{
			key->last = data;
			key->first->next = data;
		}
		else
		{
			temp = key->last;
			data->next = 0;
			temp->next = data;
			key->last = data;
		}
	}
}

t_list	*ft_ffpopfront(t_ffqueue *key)
{
	t_list	*temp;

	if (!key)
		return (0);
	else
	{
		if (key->first)
		{
			key->qlen ? key->qlen-- : key->qlen;
			temp = key->first;
			key->first = key->first->next;
			temp->next = 0;
			return (temp);
		}
	}
	return (0);
}

t_list	*ft_ffpopend(t_ffqueue *key)
{
	t_list	*temp;

	if (!key)
		return (0);
	else
	{
		if (key->last)
		{
			key->qlen ? key->qlen-- : key->qlen;
			temp = key->last;
			key->last ? key->last->next = 0 : key->last;
			return (temp);
		}
	}
	return (0);
}
