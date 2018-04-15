/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:34:10 by satkins           #+#    #+#             */
/*   Updated: 2018/04/15 13:15:20 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sh_strcat(char **front, char *back)
{
	size_t	len;

	if (!front || !back)
		return (NULL);
	len = ft_strlen(*front) + ft_strlen(back) + 1;
	if (!(*front = meta_realloc(*front, len)))
		return (NULL);
	return (ft_strcat(*front, back));
}
