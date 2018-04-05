/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:57:28 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 11:57:30 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		resize_prompt(void)
{
	char	*temp;

	temp = 0;

	cursor_to_home(&g_shell_env.cursor);
/*	cursor_to_home(&g_shell_env.cursor);
	temp = tgetstr("dl", 0);
	tputs(temp, 1, &my_putchar);
	temp = tgetstr("cl", 0);
	tputs(temp, 1, my_putchar);
	get_window_size();
	*/
}
