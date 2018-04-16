/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:32:40 by asyed             #+#    #+#             */
/*   Updated: 2018/04/15 16:47:16 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "history.h"

int		builtin_history(char *argv[], __attribute((unused))t_environ *env)
{
	if (ft_strequ(argv[1], "-d") || ft_strequ(argv[1], "--delete"))
		return (delete_history());
	else if (ft_strequ(argv[1], "-l") || ft_strequ(argv[1], "--display"))
		return (display_history());
	else
		ft_printf_fd(STDOUT_FILENO, "Usage: history [-dl]\n");
	return (EXIT_SUCCESS);
}
