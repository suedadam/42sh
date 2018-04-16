/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:33:34 by asyed             #+#    #+#             */
/*   Updated: 2018/04/16 08:45:42 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdlib.h>
#include <stdio.h>

int	builtin_export(char *argv[], __attribute__((unused)) t_environ *env)
{
	int	i;
	int	equal_index;

	if (!argv[1] || !(equal_index = ft_strchr(argv[1], '=') - argv[1]))
		return (EXIT_FAILURE);
	i = 0;
	while (env->environ[i])
	{
		if (!ft_strncmp(argv[1], env->environ[i], 
			equal_index) &&
			ft_strchr(env->environ[i], '=') - env->environ[i] == equal_index)
		{
			meta_free(env->environ[i]);
			if (!(env->environ[i] = ft_strdup(argv[1])))
				return (EXIT_FAILURE);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	env->size++;
	if (!(env->environ = meta_realloc(env->environ, (env->size + 1) * sizeof(char *))))
		return (EXIT_FAILURE);
	env->environ[env->size - 1] = ft_strdup(argv[1]);
	env->environ[env->size] = NULL;
	return (EXIT_SUCCESS);
}

int	builtin_getenv(char *argv[], t_environ *env)
{
	int	i;

	i = 0;
	if (!argv[1])
		return (EXIT_FAILURE);
	while ((env->environ)[i])
	{
		if (!ft_strncmp(argv[1], env->environ[i], 
			(ft_strchr(env->environ[i], '=') - env->environ[i])))
		{
			ft_printf_fd(STDOUT_FILENO, "%s\n", env->environ[i]);
			return (EXIT_SUCCESS);
		}
		i++;
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
	int	i;
	int	equal_index;

	if (!argv[1] || !(equal_index = ft_strchr(argv[1], '=') - argv[1]))
		return (EXIT_FAILURE);
	i = 0;
	while (env->environ[i])
	{
		if (!strncmp(argv[1], env->environ[i], 
			equal_index) &&
			ft_strchr(env->environ[i], '=') - env->environ[i] == equal_index)
		{
			meta_free(env->environ[i]);
			if (!(env->environ[i] = ft_strdup(argv[1])))
				return (EXIT_FAILURE);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	env->size++;
	if (!(env->environ = meta_realloc(env->environ, (env->size + 1) * sizeof(char *))))
		return (EXIT_FAILURE);
	env->environ[env->size - 1] = ft_strdup(argv[1]);
	env->environ[env->size] = NULL;
	return (EXIT_SUCCESS);
}

int	builtin_unsetenv(char *argv[], t_environ *env)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(argv[1]);
	while (env->environ[i])
	{
		if (!strncmp(argv[1], env->environ[i], (ft_strchr(env->environ[i], '=') - env->environ[i])))
		{
			meta_free(env->environ[i]);
			ft_memmove(&(env->environ[i]), &(env->environ[i + 1]), ((env->size - i) - 1) * sizeof(char *));
			env->size--;
			env->environ = meta_realloc(env->environ, ((env->size + 1) * sizeof(char *)));
			env->environ[env->size] = NULL;
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
