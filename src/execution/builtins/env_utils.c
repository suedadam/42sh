/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:56:41 by asyed             #+#    #+#             */
/*   Updated: 2018/04/15 19:57:03 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*__getenv(char *name, t_environ *env)
{
	int	i;

	i = 0;
	if (!name)
		return (NULL);
	while ((env->environ)[i])
	{
		if (!strncmp(name, env->environ[i], 
			(ft_strchr(env->environ[i], '=') - env->environ[i])))
			return (env->environ[i]);
		i++;
	}
	return (NULL);
}

char	**__mutgetenv(char *name, t_environ *env)
{
	int	i;

	i = 0;
	if (!name)
		return (NULL);
	while ((env->environ)[i])
	{
		if (!strncmp(name, env->environ[i], 
			(ft_strchr(env->environ[i], '=') - env->environ[i])))
			return (&(env->environ[i]));
		i++;
	}
	return (NULL);
}
