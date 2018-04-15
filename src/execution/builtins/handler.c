/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 20:35:32 by asyed             #+#    #+#             */
/*   Updated: 2018/04/14 20:05:23 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

/*
** Are unset and export really just aliases?
*/

struct s_builtins	builtins[] = {
	{"cd", &builtin_cd},
	{"echo", &builtin_echo},
	{"fg", &builtin_fg},
	// {"exit", &builtin_exit},
	{"env", &builtin_env},
	{"history", &builtin_env},
	{"setenv", &builtin_setenv},
	{"unsetenv", &builtin_unsetenv},
	{"unset", &builtin_unsetenv},
	{"export", &builtin_setenv},
	{NULL, NULL},
};

int		builtin_handler(t_ast *curr)
{
	int i;

	i = 0;
	while (builtins[i].name)
	{
		if (!strcmp(builtins[i].name, *(curr->token)))
			return (builtins[i].exec(curr->token));
		i++;
	}
	return (-1);
}
