/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_below.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:02:01 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 21:00:51 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_screen.h"
#include "ft_proto.h"

void		clear_below(void)
{
	static char *cachecd = NULL;
	static char *cachedl = NULL;

	if (!cachecd)
		cachecd = tgetstr("cd", NULL);
	if (!cachedl)
		cachedl = tgetstr("dl", NULL);
	tputs(cachecd, 1, &my_putchar);
	tputs(cachedl, 1, &my_putchar);
}
