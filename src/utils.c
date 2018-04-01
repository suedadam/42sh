/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:13:30 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/31 19:05:25 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		get_cursor_first_position(void)
{
	char	temp[42];
	int		i;

	ft_putstr_fd("\e[6n", 0);
	ft_bzero(temp, 42);
	i = read(0, temp, 42);
	temp[i] = 0;
	i = 2;
	g_shell_env.cursor.og_position.y = ft_atoi(temp + i) - 1;
	while (ft_isdigit(temp[i]))
		i++;
	g_shell_env.cursor.og_position.x = ft_atoi(temp + i + 1) - 1;
}
