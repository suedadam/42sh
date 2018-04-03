/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:43:33 by satkins           #+#    #+#             */
/*   Updated: 2018/04/03 10:44:40 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void				print_toks(char **tokens, t_token_type *types)
{
	int 			i;

	i = -1;
	while (tokens[++i])
	{
		printf("%s\t%d\n", tokens[i], types[i]);
	}
}