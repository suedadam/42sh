/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:16:12 by asyed             #+#    #+#             */
/*   Updated: 2018/03/21 21:25:04 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int	main(void)
{
	int i;
	char **tokens;

	i = 0;
	tokens = malloc(11 * sizeof(char *));
	while (i < 10)
	{
		tokens[i] = strdup("what the hell dude");
		i++;
	}
}

int	callcmd(t_ast *exec)
{
	char 	**argv;
	size_t	len;

	len = 0;
	while (argv[len])
		len++;
	memcpy(argv, exec->token, len * sizeof(char *));
	return (EXIT_SUCCESS);
}