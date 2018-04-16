/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 20:35:32 by asyed             #+#    #+#             */
/*   Updated: 2018/04/15 16:45:26 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*
** Are unset and export really just aliases?
*/

struct s_builtins	builtins[] = {
	// {"cd", &builtin_cd},
	{"echo", &builtin_echo},
	{"fg", &builtin_fg},
	// {"exit", &builtin_exit},
	{"env", &builtin_env},
	{"history", &builtin_history},
	{"getenv", &builtin_getenv},
	{"setenv", &builtin_setenv},
	{"unsetenv", &builtin_unsetenv},
	{"unset", &builtin_unsetenv},
	{"export", &builtin_setenv},
	{NULL, NULL},
};

int		builtin_handler(t_ast *curr, t_environ *env)
{
	int i;

	i = 0;
	if (handle_redirection(curr))
		return (EXIT_FAILURE);
	while (builtins[i].name)
	{
		if (!strcmp(builtins[i].name, *(curr->token)))
			return (builtins[i].exec(curr->token, env));
		i++;
	}
	return (-1);
}
