/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 22:34:50 by asyed             #+#    #+#             */
/*   Updated: 2018/04/13 22:47:54 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		compare(int *n1, int *n2)
{
	if (*n1 > *n2)
		return (0);
	return (1);
}

inline __attribute__((always_inline)) void	*init_process(void)
{
	t_process	*new;

	if (!(new = ft_memalloc(sizeof(t_process))))
		return (NULL);
	else if (!(new->stdin = ft_memalloc(sizeof(int) * 2)))
	{
		meta_free(new);
	}
	else if (!(new->stderr = ft_memalloc(sizeof(int) * 2)))
	{
		meta_free(new);
		meta_free(new->stdin);
	}
	else if (!(new->stdout = ft_memalloc(sizeof(int) * 2)))
	{
		meta_free(new);
		meta_free(new->stdin);
		meta_free(new->stderr);
	}
	else if (!(new->comm = ft_memalloc(sizeof(int) * 2)))
	{
		meta_free(new);
		meta_free(new->stdin);
		meta_free(new->stderr);
		meta_free(new->stdout);
	}
	else
		return (new);
	return (NULL);
}
