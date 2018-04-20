/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strappend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:38:00 by satkins           #+#    #+#             */
/*   Updated: 2018/04/15 17:04:44 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

char				*strappend(char **str, char c)
{
	int				length;

	length = ft_strlen(*str);
	if (!(*str = meta_realloc(*str, length + 2)))
		return (NULL);
	*str = ft_strncat(*str, &c, 1);
	(*str)[length + 1] = '\0';
	return (*str);
}
