/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:45:25 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/06 15:11:16 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			reset_buffer(void)
{
	free(g_shell_env.buffer->buff);
	free(g_shell_env.buffer);
	return (init_buffer());
}
