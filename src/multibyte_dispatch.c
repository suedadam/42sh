/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibyte_dispatch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:26:22 by nkouris           #+#    #+#             */
/*   Updated: 2018/03/29 16:36:16 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int		read_multibyte(char byte, int *mpass, t_terminf *anti)
{
	char	discard[2];

	else if (*mpass && LSEEK(byte))
		line_seek(anti, byte);
	else if (*mpass && DEL(byte))
	{
		read(STDIN_FILENO, &discard, 1);
		ft_printf("\ndelete key\n");
	}
	else if (*mpass && SCRL(byte))
	{
		read(STDIN_FILENO, &discard, 1);
		ft_printf("\npgup or pgdwn\n");
	}
	else if (*mpass && HIST(byte))
		ft_printf("\narrup or arrdwn\n");
	else if (*mpass == 2 && byte == '1')
	{
		read(STDIN_FILENO, &discard, 2);
		ft_printf("\nshift\n");
	}
	*mpass = 0;
	return (EXIT_SUCCESS);
}
