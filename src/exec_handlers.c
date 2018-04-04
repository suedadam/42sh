/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 09:47:11 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/03 17:15:58 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

/*
static void		ft_idonothing(int signal)
{
	signal = 0;
	ft_printf("I do nothing amd i am ft_idonothing\n");
	return ;
}

static void		ft_window(int signal)
{

	ft_printf("I do nothing amd I am ft_window\n");
	return ;
	signal = 0;
}
*/
void			handle_sign(int signal)
{
	char *str;

	ft_printf("coucou\n");
	if (signal != SIGQUIT)
		ft_printf("hey\n");
	if ((str = tgetstr("ve", NULL)) == NULL)
		return ;
	tputs(str, 1, my_putchar);
	ft_printf("I have pushed escape key\n");
	exit(1);
}

int		quote_mode(char byte)
{
	char	*temp;

	temp = tgetstr("do", 0);
	tputs(temp, 1, my_putchar);
	ft_printf("ici");
	if (byte == '\'')
	{
		// ft_printf("quote> ");
		new_prompt("quote> ");
	}
	else
		new_prompt("dquote> ");
		// ft_printf("dquote> ");
	return (EXIT_SUCCESS);
}
