/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <satkins@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:36:01 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/18 18:14:59 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cursor.h"
#include "ft_proto.h"

void		get_cursor_first_position(void)
{
	char	temp[42];
	int		i;

	ft_putstr_fd("\e[6n", STDIN_FILENO);
	ft_bzero(temp, 42);
	if ((i = read(STDIN_FILENO, temp, 9)) < 0)
		return ;
	temp[i] = '\0';
	i = 2;
	g_shell_env.cursor.og_position.y = ft_atoi(temp + i) - 1;
	while (ft_isdigit(temp[i]))
		i++;
	g_shell_env.cursor.og_position.x = ft_atoi(temp + i + 1) - 1;
}
