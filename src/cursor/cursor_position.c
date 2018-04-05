/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:36:01 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 11:36:11 by nkouris          ###   ########.fr       */
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

void		get_cursor_current_position(void)
{
	char	temp[42];
	int		i;

	ft_putstr_fd("\e[6n", 0);
	ft_bzero(temp, 42);
	i = read(0, temp, 42);
	temp[i] = 0;
	i = 2;
	g_shell_env.cursor.res_position.y = ft_atoi(temp + i) - 1;
	while (ft_isdigit(temp[i]))
		i++;
	g_shell_env.cursor.res_position.x = ft_atoi(temp + i + 1) - 1;
}