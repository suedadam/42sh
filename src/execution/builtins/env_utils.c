/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:56:41 by asyed             #+#    #+#             */
/*   Updated: 2018/04/16 08:45:29 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	*ft_getenv(char *name, t_environ *env)
{
	int		i;
	char	*ret;

	i = 0;
	if (!name)
		return (NULL);
	while ((env->environ)[i])
	{
		if (!ft_strncmp(name, env->environ[i],
			((ret = ft_strchr(env->environ[i], '=')) - env->environ[i])))
			return (ret + 1);
		i++;
	}
	return (NULL);
}

char	**ft_mutgetenv(char *name, t_environ *env)
{
	int	i;

	i = 0;
	if (!name)
		return (NULL);
	while ((env->environ)[i])
	{
		if (!ft_strncmp(name, env->environ[i],
			(ft_strchr(env->environ[i], '=') - env->environ[i])))
			return (&(env->environ[i]));
		i++;
	}
	return (NULL);
}
