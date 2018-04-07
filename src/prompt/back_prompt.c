/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:56:33 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 18:28:25 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		back_prompt(void)
{
	char	*temp;

	temp = tgetstr("do", NULL);
	tputs(temp, 1, my_putchar);
	new_prompt("> ");
	// n = ft_printf("> ");
	// g_shell_env.prompt_length = n;
	get_cursor_first_position();
}
