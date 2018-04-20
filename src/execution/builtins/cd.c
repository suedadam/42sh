/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 21:29:30 by asyed             #+#    #+#             */
/*   Updated: 2018/04/20 11:52:56 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <string.h>
#include <errno.h>

extern char **environ;

void		parse_relative(char **str)
{
	char	*res;
	char	*tmp;
	size_t	len;

	if (!(len = ft_strlen(*str)))
		return ;
	while ((res = ft_strstr(*str, "..")))
	{
		if (!(*res))
			return ;
		*(res - 1) = '\0';
		if (!(tmp = ft_strrchr(*str, '/')))
			return ;
		*(res - 1) = '/';
		if ((len = ft_strlen(res)) > 2)
		{
			ft_memmove(tmp, res + 2, len - 2);
			tmp[len - 2] = '\0';
		}
		else if (len == 2)
			ft_memmove(tmp, "/\0", 2);
		else if (tmp)
			*tmp = '\0';
	}
}

static int	absolute_update(char **l_pwd, t_environ *env, char *input, size_t inlen)
{
	if (!(*l_pwd = meta_realloc(*l_pwd, 4 + inlen + 2)))
		return (EXIT_FAILURE);
	ft_bzero(&((*l_pwd)[4]), inlen + 2);
	if (!(*l_pwd = ft_strcat(*l_pwd, input)))
		return (EXIT_FAILURE);
	parse_relative(l_pwd);
	if (chdir(&((*l_pwd)[4])) == -1)
	{
		ft_printf("Error: %s\n", ft_strerror(errno));
		return (EXIT_SUCCESS);
	}
	if (builtin_setenv((char *[]){NULL, *l_pwd}, env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	relative_update(char **l_pwd, t_environ *env, char *input, size_t inlen)
{
	size_t	len;

	len = ft_strlen(*l_pwd);
	*l_pwd = meta_realloc(*l_pwd, len + inlen + 2);
	(*l_pwd)[len] = '/';
	if (!(*l_pwd = ft_strcat(*l_pwd, input)))
		return (EXIT_FAILURE);
	parse_relative(l_pwd);
	if (chdir(&((*l_pwd)[4])) == -1)
	{
		ft_printf("Error: %s (%s)\n", ft_strerror(errno), *l_pwd);
		return (EXIT_SUCCESS);
	}

	if (builtin_setenv((char *[]){NULL, *l_pwd}, env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	set_old_pwd(char **res, t_environ *env)
{
	char *old_pwd;

	if (!(old_pwd = meta_malloc(ft_strlen(*res) + OLD_PWD_OFFSET + 1)))
		return (EXIT_FAILURE);
	ft_strcpy(old_pwd, "OLDPWD=");
	ft_strcat(old_pwd, &((*res)[4]));
	if (builtin_setenv((char *[]){NULL, old_pwd}, env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	meta_free(old_pwd);
	return (EXIT_SUCCESS);
}

int			builtin_cd(char *argv[], t_environ *env)
{
	int		len;
	char	**res;
	char	*l_pwd;
	char	*home;

	if (!argv[0]
		|| !(res = ft_mutgetenv("PWD", env))
		|| !(l_pwd = ft_strdup(*res))
		|| set_old_pwd(res, env) == EXIT_FAILURE
		|| builtin_unsetenv(((char *[]){NULL, *res}), env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (!argv[1] || !(len = ft_strlen(argv[1])) || argv[1][0] == '~')
	{
		if (!(home = ft_getenv("HOME", env)))
			return (EXIT_FAILURE);
		return (absolute_update(&l_pwd, env, home, ft_strlen(home)));
	}
	else if (argv[1][0] == '/')
		return (absolute_update(&l_pwd, env, argv[1], len));
	else if (argv[1][0] == '.' && len == 1)
		return (EXIT_SUCCESS);
	return (relative_update(&l_pwd, env, argv[1], len));
}
