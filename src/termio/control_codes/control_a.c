/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:38:16 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/09 19:21:34 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_control.h"
#include "ft_proto.h"

int		control_a(void)
{
	cursor_to_home(&g_shell_env.cursor);
	return (EXIT_SUCCESS);
}
