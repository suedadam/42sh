/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 09:47:11 by nkouris           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/30 18:09:52 by nkouris          ###   ########.fr       */
=======
/*   Updated: 2018/03/31 15:15:44 by tle-huu-         ###   ########.fr       */
>>>>>>> termio
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
<<<<<<< HEAD

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
=======
// 
// static void		ft_idonothing(int signal)
// {
// 	signal = 0;
// 	ft_printf("I do nothing amd i am ft_idonothing\n");
// 	return ;
// }
//
// static void		ft_window(int signal)
// {
//
// 	ft_printf("I do nothing amd I am ft_window\n");
// 	return ;
// 	signal = 0;
// }

>>>>>>> termio
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
	if (byte == '\'')
		ft_printf("quote> ");
	else
		ft_printf("dquote> ");
	return (EXIT_SUCCESS);
}
