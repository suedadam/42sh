/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 23:07:15 by sgardner          #+#    #+#             */
/*   Updated: 2018/03/21 21:43:45 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*sub;

	if ((sub = (char *)malloc(len + 1)))
	{
		ft_memcpy(sub, s + start, len);
		sub[len] = '\0';
	}
	return (sub);
}
