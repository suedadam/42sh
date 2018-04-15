/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 21:29:30 by asyed             #+#    #+#             */
/*   Updated: 2018/04/14 17:30:47 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	builtin_cd(char *argv[], t_environ *env)
{
	int	i;
	int	res;
	int	len;

	i = 0;
	if (!argv[1] || !(len = strlen(argv[1])))
		return (EXIT_FAILURE);
	while (env->environ[i])
	{
		if ((res = strcmp("PWD", env->environ[i])) <= 0 &&
			(!res || -res == '='))
		{
			if (argv[1][0] == '/')
			{
				printf("in here ;) \n");
				printf("\"%s\" %p %d\n", g_environ->environ[i], g_environ->environ[i], len + 4);
				// g_environ->environ[i] = realloc(g_environ->environ[i], len + 4);
				printf("\"%s\" %p\n", g_environ->environ[i], g_environ->environ[i]);
				memcpy(&(g_environ->environ[i][4]), argv[1], (len + 1) * sizeof(char)); //Copy NULL terminator.
			}
			printf("DONE! CHANGED TO \"%s\"\n", g_environ->environ[i]);
			return (EXIT_SUCCESS);
		}
		// else
		// {
		// 	printf("%d (%d vs %d) -> %s\n", res, -res, '=', g_environ->environ[i]);
		// }
		i++;
	}
	// if (!argv[1] || !strchr(argv[1], '='))
	// 	return (EXIT_FAILURE);
	// if (!(g_environ->environ = realloc(g_environ->environ, (g_environ->size + 1) * sizeof(char **))))
	// 	return (EXIT_FAILURE);
	// g_environ->size++;
	// g_environ->environ[g_environ->size - 1] = argv[1];
	// printf("%zu = %s\n", g_environ->size, g_environ->environ[g_environ->size - 1]);
	return (EXIT_FAILURE);
}