/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_op_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:36:32 by satkins           #+#    #+#             */
/*   Updated: 2018/04/14 02:06:39 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static	int			cmp(char *str, size_t len)
{
	int				i;

	i = -1;
	while (++i < OPS)
		if (!ft_strncmp(ops[i], str, len + 1))
			return (1);
	return (0);
}

int					is_op_append(char *token, char c)
{
	char			tmp[3];
	size_t			len;
	int				i;

	len = ft_strlen(token);
	if (len > 2)
		return (0);
	else if (len == 0)
	{
		tmp[0] = c;
		tmp[1] = '\0';
	}
	else if (len == 1)
	{
		tmp[0] = *token;
		tmp[1] = c;
		tmp[2] = '\0';
	}
	else
		return (!c && cmp(token, 2));
	return (cmp(tmp, len));
	
}
