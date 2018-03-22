/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 07:54:57 by sgardner          #+#    #+#             */
/*   Updated: 2018/03/21 21:43:40 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!*s2)
		return ((char *)s1);
	while (n && *s1)
	{
		i = 0;
		while (i < n && s1[i])
		{
			if (s1[i] != s2[i])
				break ;
			++i;
		}
		if (!s2[i])
			return ((char *)s1);
		++s1;
		--n;
	}
	return (NULL);
}
