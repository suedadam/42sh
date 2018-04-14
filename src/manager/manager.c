/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:56:05 by asyed             #+#    #+#             */
/*   Updated: 2018/04/14 12:27:21 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
**
** Free input_str after parser().
*/

int	manager(char *input_str, char **substr)
{
	t_ast 	*res;
	void	*forest;
	int		ret;

	if (!input_str)
		return (EXIT_FAILURE);
	if (!(res = parser(input_str)) || res == MAP_FAILED)
	{
		free(input_str);
		return ((!res) ? EXIT_FAILURE : EXIT_FAILURE_SOFT);
	}
	if (!(forest = build_forest(res->token, res->type)))
	{
		free(input_str);
		// free_segs(res);
		return (EXIT_FAILURE);
	}
	ret = run_forest(forest, substr);
	free(input_str);
	return (ret);
}
