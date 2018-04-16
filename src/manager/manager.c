/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:56:05 by asyed             #+#    #+#             */
/*   Updated: 2018/04/16 08:54:24 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_proto.h"

static void			free_env(t_environ *env)
{
	size_t	i;

	i = 0;
	while (i < env->size)
	{
		meta_free(env->environ[i]);
		i++;
	}
	meta_free(env->environ);
	meta_free(env);
}

static t_environ	*set_local_env(int subshell_env)
{
	size_t		i;
	t_environ	*env;

	if (!subshell_env)
		return (g_environ);
	if (!(env = ft_memalloc(sizeof(t_environ))) ||
		!(env->environ = ft_memalloc(sizeof(char *) * (g_environ->size + 1))))
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
	t_ast		*res;
	void		*forest;
	int			ret;
	t_environ	*env;

	if (!input_str)
		return (EXIT_FAILURE);
	if (!(res = parser(input_str)) || res == MAP_FAILED)
		return ((!res) ? EXIT_FAILURE : EXIT_FAILURE_SOFT);
	if (!(forest = build_forest(res->token, res->type)))
		return (EXIT_FAILURE);
	meta_free(res->type);
	meta_free(res->token);
	meta_free(res);
	if (!(env = set_local_env(substr != NULL ? 1 : 0)))
		return (EXIT_FAILURE);
	ft_restoretty();
	ret = run_forest(forest, substr, env);
	meta_free(forest);
	if (substr != NULL)
		free_env(env);
	ft_setty();
	return (ret);
}
