/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:36:11 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/13 22:10:16 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"
#include "ft_proto.h"

void	del_paths(char **mul_paths)
{
	char	**temp;

	temp = mul_paths;
	while (*temp)
		meta_free(*temp++);
	meta_free(mul_paths);
}
