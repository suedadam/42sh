/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:36:32 by satkins           #+#    #+#             */
/*   Updated: 2018/04/03 10:36:57 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int					is_op(char *token, char c)
{
	char			tmp[3];
	size_t			len;
	int				i;

	len = ft_strlen(token);
	if (len > 1)
		return (0);
	else if (len == 0)
	{
		tmp[0] = c;
		tmp[1] = '\0';
	}
	else
	{
		tmp[0] = *token;
		tmp[1] = c;
		tmp[2] = '\0';
	}
	i = -1;
	while (++i < OPS)
		if (!ft_strncmp(ops[i], tmp, len + 1))
			return (1);
	return (0);
}
