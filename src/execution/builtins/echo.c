/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 14:20:22 by satkins           #+#    #+#             */
/*   Updated: 2018/04/14 16:48:46 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	builtin_echo(char *argv[], __attribute__((unused))t_environ *e)
{
	uint8_t	nl;
	int		i;

	if (!argv || !argv[0] || !ft_strequ("echo", argv[0]))
		return (EXIT_FAILURE);
	nl = ft_strequ("-n", argv[1]) ? 0 : 1;
	i = nl ? 1 : 2;
	while (argv[i])
	{
		ft_printf_fd(STDOUT_FILENO, "%s", argv[i]);
		i++;
		if (argv[i])
			ft_printf_fd(STDOUT_FILENO, " ");
	}
	if (nl)
		ft_printf_fd(STDOUT_FILENO, "\n");
	return (EXIT_SUCCESS);
}

// int	main(int argc, char **argv)
// {
// 	if (argc == 1)
// 		return (0);
// 	builtin_echo(&(argv[1]));
// 	return (0);
// }
