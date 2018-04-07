/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:52:12 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 19:38:15 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *bloc;

	size = size + 1;
	bloc = (char*)ft_memalloc(sizeof(char) * size);
	if (!bloc)
		return (0);
	return (bloc);
}
