/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:16:25 by asyed             #+#    #+#             */
/*   Updated: 2018/03/22 13:45:25 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *src, size_t new_size)
{
	void	*new;

	if (!src)
		return (ft_memalloc(new_size));
	if (!new_size)
	{
		free(src);
		return (NULL);
	}
	new = (void *)ft_memalloc(new_size);
	if (!new)
		return (NULL);
	new = ft_memcpy(new, src, new_size);
	free(src);
	return (new);
}