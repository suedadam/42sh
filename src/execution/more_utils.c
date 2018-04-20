/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:30:08 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/19 19:38:39 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		compare(int *n1, int *n2)
{
	if (*n1 < *n2)
		return (0);
	return (1);
}

void	linkfree(t_node *list, t_jobspec *job)
{
	if (list->previous)
		list->previous = list->next;
	if (list->next)
		list->next->previous = list->previous;
	meta_free(job->name);
	meta_free(job);
	meta_free(list);
}
