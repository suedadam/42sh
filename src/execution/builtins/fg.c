/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:05:58 by asyed             #+#    #+#             */
/*   Updated: 2018/04/14 20:15:54 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	builtin_fg(char *argv[], __attribute__((unused)) t_environ *env)
{
	if (!argv || !argv[0])
		return (EXIT_FAILURE);
	unsuspend(argv[1]);
	return (EXIT_SUCCESS);
}
