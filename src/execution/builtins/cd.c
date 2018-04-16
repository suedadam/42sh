/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 21:29:30 by asyed             #+#    #+#             */
/*   Updated: 2018/04/15 23:16:39 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <string.h>
#include <errno.h>

static int	absolute_update(char **l_pwd, char **res, char *input, size_t inlen)
{
	if (!(*l_pwd = meta_realloc(*l_pwd, 4 + inlen + 2)))
		return (EXIT_FAILURE);
	bzero(&((*l_pwd)[4]), inlen + 2);
	if (!(*l_pwd = ft_strcat(*l_pwd, input)))
		return (EXIT_FAILURE);
	if (chdir(&((*l_pwd)[4])) == -1)
	{
		ft_printf("Error: %s\n", ft_strerror(errno));
		return (EXIT_FAILURE);
	}
	*res = *l_pwd;
	return (EXIT_SUCCESS);
}

static int	relative_update(char **l_pwd, char **res, char *input, size_t inlen)
{
	size_t	len;

	len = ft_strlen(*l_pwd);
	*l_pwd = meta_realloc(*l_pwd, len + inlen + 2);
	(*l_pwd)[len] = '/';
	if (!(*l_pwd = ft_strcat(*l_pwd, input)))
		return (EXIT_FAILURE);
	//error handle here.
	if (chdir(&((*l_pwd)[4])) == -1)
	{
		ft_printf("Error: %s\n", ft_strerror(errno));
		return (EXIT_SUCCESS);
	}
	*res = *l_pwd;
	return (EXIT_SUCCESS);
}

int			builtin_cd(char *argv[], t_environ *env)
{
	int		len;
	char	**res;
	char	*l_pwd;
	char	*home;

	if (!argv[0] || !argv[1] || !(len = strlen(argv[1])))
		return (EXIT_FAILURE);
	if (!(res = __mutgetenv("PWD", env)))
	{
		//Create a PWD.
		return (EXIT_FAILURE);
	}
	l_pwd = ft_strdup(*res);
	if (argv[1][0] == '/')
		return (absolute_update(&l_pwd, res, argv[1], len));
	else if (argv[1][0] == '~')
	{
		if (!(home = __getenv("HOME", env)))
			return (EXIT_FAILURE);
		return (absolute_update(&l_pwd, res, home, strlen(home)));
	}
	return (relative_update(&l_pwd, res, argv[1], len));
}
