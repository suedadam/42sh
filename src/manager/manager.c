/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:56:05 by asyed             #+#    #+#             */
/*   Updated: 2018/04/14 17:33:16 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static t_environ	*set_local_env(int subshell_env)
{
	size_t		i;
	t_environ	*env;

	if (!subshell_env)
		return (g_environ);
	if (!(env = malloc(sizeof(t_environ))) ||
		!(env->environ = malloc(sizeof(char *) * g_environ->size + 1)))
		return (NULL);
	i = 0;
	while (i < g_environ->size)
	{
		if (!(env->environ[i] = ft_strdup(g_environ->environ[i])))
			return (NULL);
		i++;
	}
	env->environ[i] = NULL;
	env->size = g_environ->size;
	return (env);	
}

int	manager(char *input_str, char **substr)
{
	t_ast 		*res;
	void		*forest;
	int			ret;
	t_environ	*env;

	if (!input_str)
		return (EXIT_FAILURE);
	if (!(res = parser(input_str)) || res == MAP_FAILED)
		return ((!res) ? EXIT_FAILURE : EXIT_FAILURE_SOFT);
	if (!(forest = build_forest(res->token, res->type)))
	{
		// free_segs(res);
		return (EXIT_FAILURE);
	}
	if (!(env = set_local_env(substr != NULL ? 1 : 0)))
		return (EXIT_FAILURE);
	ret = run_forest(forest, substr, env);
	return (ret);
}
