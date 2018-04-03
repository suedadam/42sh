/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:56:05 by asyed             #+#    #+#             */
/*   Updated: 2018/04/02 23:57:03 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void	*init_environ(void)
{
	t_environ	*new;
	int			i;

	if (!g_environ)
		return (NULL);
	if (!(new = ft_memalloc(sizeof(t_environ))))
		return (NULL);
	if (!(new->environ = ft_memalloc(sizeof(char **) * g_environ->size)))
	{
		free(new);
		return (NULL);
	}
	i = 0;
	while (new->environ[i])
	{
		new->environ[i] = strdup(g_environ->environ[i]);
		i++;
	}
	new->size = g_environ->size;
	return (new);
}

int	manager(char *input_str, uint8_t persistent)
{
	t_environ									*usable;
	void __attribute__ ((unused))				*res;
	void __attribute__ ((unused))				*ast;

	if (!input_str)
		return (EXIT_FAILURE);
	if (!(usable = (persistent ? g_environ : init_environ())))
		return (EXIT_FAILURE);
	// if (!(res = parser(input_str) == EXIT_FAILURE))
	// 	return (EXIT_FAILURE);
	// if (!(ast = build_forest(res)))

	if (persistent)
	{
		free(usable->environ);
		free(usable);
	}
	return (EXIT_SUCCESS);
}