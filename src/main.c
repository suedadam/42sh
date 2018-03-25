/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:46:18 by sgardner          #+#    #+#             */
/*   Updated: 2018/03/25 00:04:10 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

char	*g_pname;

int		main(int ac, char **av, char **ev)
{
	UNUSED(ac);
	UNUSED(ev);
	g_pname = av[0] + 2;
	return (0);
}
