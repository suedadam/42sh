/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:08:32 by sgardner          #+#    #+#             */
/*   Updated: 2018/03/21 21:43:13 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n && s1[len])
		++len;
	if (len == n)
		return (len + ft_strlen(s2));
	return (len + ft_strlcpy(s1 + len, s2, n - len));
}
