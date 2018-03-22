/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 00:42:57 by sgardner          #+#    #+#             */
/*   Updated: 2018/03/21 21:52:09 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_memmgr.h"

void	*ft_mlalloc(t_mchain *mchain, size_t size)
{
	void	*ptr;

	if (!(ptr = ft_memalloc(size)))
		return (NULL);
	if (!ft_mladd(mchain, ptr, size))
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}
