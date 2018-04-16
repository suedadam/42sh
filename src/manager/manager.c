/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:56:05 by asyed             #+#    #+#             */
/*   Updated: 2018/04/15 12:06:36 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void			free_env(t_environ *env)
{
	size_t	i;

	i = 0;
	while (i < env->size)
	{
		free(env->environ[i]);
		i++;
	}
	free(env->environ);
	free(env);
}

static t_environ	*set_local_env(int subshell_env)
{
	size_t		i;
	t_environ	*env;

	if (!subshell_env)
		return (g_environ);
	if (!(env = ft_memalloc(sizeof(t_environ))) ||
		!(env->environ = ft_memalloc(sizeof(char *) * g_environ->size + 1)))
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
		// ft_printf("Got here?\n");
		return (EXIT_FAILURE);
	}
	// ft_printf("Nick\n");
	if (!(env = set_local_env(substr != NULL ? 1 : 0)))
		return (EXIT_FAILURE);
	// ft_printf("Greg....\n");
	ret = run_forest(forest, substr, env);
	if (substr != NULL)
		free_env(env);
	return (ret);
}
