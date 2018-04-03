/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:33:34 by asyed             #+#    #+#             */
/*   Updated: 2018/04/03 00:15:45 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdlib.h>

int	cmd_env(__attribute__((unused)) char *argv[], t_environ *environ)
{
	int	i;

	i = 0;
	while ((environ->environ)[i])
		ft_putstr((environ->environ)[i++]);
	return (EXIT_SUCCESS);
}

int	cmd_setenv(char *argv[], t_environ *environ)
{
	int		i;
	char	*val;

	i = 0;
	while (argv[1][i])
	{
		if (IS_WHITESPACE(argv[1][i]))
		{
			val = strdup(&(argv[1][i]));
			break ;
		}
		i++;
	}
	if (!(environ->environ = realloc(environ->environ, (environ->size + 1) * sizeof(char **))))
	{
		free(val);
		return (EXIT_FAILURE);
	}
	environ->size++;
	environ->environ[environ->size] = val;
	return (EXIT_SUCCESS);
}

/*
** Tested logic - should work work fine.
** https://gist.github.com/suedadam/f70fa11e3aa0e6953286fa3ae951be5b
** My realloc doesn't change sizes when its smaller than the block's size so the realloc won't be doing anything. 
*/

int	cmd_unsetenv(char *argv[], t_environ *environ)
{
	int		i;
	int		res;
	int		len;

	i = 0;

	len = strlen(argv[1]);
	while (environ->environ[i])
	{
		if ((res = ft_strcmp(argv[1], environ->environ[i])) <= 0 &&
			(!res || -environ->environ[i][len] == res))
		{
			free(environ->environ[i]);
			memcpy(&(environ->environ[i]), &(environ->environ[i + 1]), ((environ->size - i) - 1) * sizeof(char *));
			environ->environ = realloc(environ->environ, (environ->size - 1 * sizeof(char *)));
			environ->size--;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
