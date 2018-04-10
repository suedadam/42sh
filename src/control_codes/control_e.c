/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:40:12 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 18:47:41 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_control.h"
#include "ft_proto.h"

int		control_e(void)
{
	cursor_to_end(&g_shell_env.cursor);
	return (EXIT_SUCCESS);
}
