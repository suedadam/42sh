/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 11:19:32 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/06 22:33:03 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			ft_backspace(void)
{
	t_cursor	*cursor;

	cursor = &(g_shell_env.cursor);
	if (cursor->position > 0)
	{
		cursor->position--;
		return (ft_delete(-1));
	}
	return (EXIT_SUCCESS);
}
