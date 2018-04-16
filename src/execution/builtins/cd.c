/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 21:29:30 by asyed             #+#    #+#             */
/*   Updated: 2018/04/16 07:26:02 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <string.h>
#include <errno.h>

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
		if ((len = strlen(res)) > 2)
		{
			ft_memmove(tmp, res + 2, len - 2);
			tmp[len - 2] = '\0';
		}
		else if (tmp)
			*tmp = '\0';
	}
}

static int	absolute_update(char **l_pwd, char **res, char *input, size_t inlen)
{
	if (!(*l_pwd = meta_realloc(*l_pwd, 4 + inlen + 2)))
		return (EXIT_FAILURE);
	bzero(&((*l_pwd)[4]), inlen + 2);
	if (!(*l_pwd = ft_strcat(*l_pwd, input)))
		return (EXIT_FAILURE);
	parse_relative(l_pwd);
	if (chdir(&((*l_pwd)[4])) == -1)
	{
		ft_printf("Error: %s\n", ft_strerror(errno));
		return (EXIT_SUCCESS);
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
	parse_relative(l_pwd);
	if (chdir(&((*l_pwd)[4])) == -1)
	{
		ft_printf("Error: %s (%s)\n", ft_strerror(errno), *l_pwd);
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

	if (!argv[0])
		return (EXIT_FAILURE);
	if (!(res = ft_mutgetenv("PWD", env)))
		return (EXIT_FAILURE);
	l_pwd = ft_strdup(*res);
	if (!argv[1] || !(len = ft_strlen(argv[1])) || argv[1][0] == '~')
	{
		if (!(home = ft_getenv("HOME", env)))
			return (EXIT_FAILURE);
		return (absolute_update(&l_pwd, res, home, strlen(home)));
	}
	else if (argv[1][0] == '/')
		return (absolute_update(&l_pwd, res, argv[1], len));
	else if (argv[1][0] == '.' && len == 1)
		return (EXIT_SUCCESS);
	return (relative_update(&l_pwd, res, argv[1], len));
}
