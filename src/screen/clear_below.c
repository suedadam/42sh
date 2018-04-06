/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_below.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:02:01 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 17:14:03 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		clear_below(void)
{
	char	*temp;

	temp = tgetstr("cd", 0);
	tputs(temp, 1, &my_putchar);
	temp = tgetstr("dl", 0);
	tputs(temp, 1, &my_putchar);
}
