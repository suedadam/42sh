/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 01:15:03 by sgardner          #+#    #+#             */
/*   Updated: 2018/03/21 23:30:06 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	const t_byte	*src;
	t_byte			*dst;
	size_t			i;

	src = (const t_byte *)s2;
	dst = (t_byte *)s1;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		++i;
	}
	return (s1);
}
