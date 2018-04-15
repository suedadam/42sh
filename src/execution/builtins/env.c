/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:33:34 by asyed             #+#    #+#             */
/*   Updated: 2018/04/14 17:06:04 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdlib.h>
#include <stdio.h>

/*
** Custom builtin
*/

int	builtin_getenv(char *argv[], t_environ *env)
{
	int	i;
	int	ret;

	i = 0;
	if (!argv[1])
		return (EXIT_FAILURE);
	while ((env->environ)[i])
	{
		if ((ret = strcmp(argv[1], env->environ[i])) <= 0 && 
			(!ret || -ret == '='))
		{
			ft_printf_fd(STDOUT_FILENO, "%s\n", env->environ[i]);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}


int	builtin_env(__attribute__((unused)) char *argv[], t_environ *env)
{
	int	i;

	i = 0;
	while ((env->environ)[i])
	{
		ft_printf_fd(STDOUT_FILENO, "%s\n", env->environ[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	builtin_setenv(char *argv[], t_environ *env)
{
	if (!argv[1] || !ft_strchr(argv[1], '='))
		return (EXIT_FAILURE);
	env->size++;
	if (!(env->environ = realloc(env->environ, (env->size + 1) * sizeof(char *))))
		return (EXIT_FAILURE);
	env->environ[env->size - 1] = ft_strdup(argv[1]);
	// printf("%zu = %s\n", g_environ->size, g_environ->environ[g_environ->size - 1]);
	return (EXIT_SUCCESS);
}

/*
** Tested logic - should work work fine.
** https://gist.github.com/suedadam/f70fa11e3aa0e6953286fa3ae951be5b
** My realloc doesn't change sizes when its smaller than the block's size so the realloc won't be doing anything. 
*/

int	builtin_unsetenv(char *argv[], t_environ *env)
{
	int		i;
	int		res;
	int		len;

	i = 0;
	len = ft_strlen(argv[1]);
	while (env->environ[i])
	{
		if ((res = strcmp(argv[1], env->environ[i])) <= 0 &&
			(!res || -res == '='))
		{
			free(env->environ[i]);
			memcpy(&(env->environ[i]), &(env->environ[i + 1]), ((env->size - i) - 1) * sizeof(char *));
			g_environ->size--;
			env->environ = realloc(env->environ, ((env->size + 1) * sizeof(char *)));
			env->environ[env->size] = NULL;
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
