/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:56:33 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 11:57:14 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		back_prompt(void)
{
	char	*temp;
	// int		n;

	temp = tgetstr("do", 0);
	tputs(temp, 1, my_putchar);
	new_prompt("> ");
	// n = ft_printf("> ");
	// g_shell_env.prompt_length = n;
	get_cursor_first_position();
}
