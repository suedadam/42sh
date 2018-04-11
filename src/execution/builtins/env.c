/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:33:34 by asyed             #+#    #+#             */
/*   Updated: 2018/04/04 16:45:50 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdlib.h>
#include <stdio.h>

/*
** Custom builtin
*/

int	builtin_getenv(char *argv[])
{
	int	i;
	int	len;
	int	ret;

	i = 0;
	if (!arv[1] || !(len = argv[1]))
		return (EXIT_FAILURE);
	while ((g_environ->environ)[i])
	{
		if ((ret = strcmp(argv[1], g_environ->environ[i])) <= 0 && 
			(!ret || -ret == '='))
		{
			printf("Found it!\n");
		}
		// ft_putstr((g_environ->environ)[i++]);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (EXIT_SUCCESS);
}


int	builtin_env(__attribute__((unused)) char *argv[])
{
	int	i;

	i = 0;
	while ((g_environ->environ)[i])
	{
		ft_putstr((g_environ->environ)[i++]);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (EXIT_SUCCESS);
}

int	builtin_setenv(char *argv[])
{
	if (!argv[1] || !strchr(argv[1], '='))
		return (EXIT_FAILURE);
	if (!(g_environ->environ = realloc(g_environ->environ, (g_environ->size + 1) * sizeof(char **))))
		return (EXIT_FAILURE);
	g_environ->size++;
	g_environ->environ[g_environ->size - 1] = argv[1];
	printf("%zu = %s\n", g_environ->size, g_environ->environ[g_environ->size - 1]);
	return (EXIT_SUCCESS);
}

/*
** Tested logic - should work work fine.
** https://gist.github.com/suedadam/f70fa11e3aa0e6953286fa3ae951be5b
** My realloc doesn't change sizes when its smaller than the block's size so the realloc won't be doing anything. 
*/

int	builtin_unsetenv(char *argv[])
{
	int		i;
	int		res;
	int		len;

	i = 0;
	len = strlen(argv[1]);
	while (g_environ->environ[i])
	{
		if ((res = ft_strcmp(argv[1], g_environ->environ[i])) <= 0 &&
			(!res || -res == '='))
		{
			free(g_environ->environ[i]);
			memcpy(&(g_environ->environ[i]), &(g_environ->environ[i + 1]), ((g_environ->size - i) - 1) * sizeof(char *));
			g_environ->environ = realloc(g_environ->environ, (g_environ->size - 1 * sizeof(char *)));
			g_environ->environ[g_environ->size - 1] = NULL;
			g_environ->size--;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
