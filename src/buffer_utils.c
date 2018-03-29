/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:18:24 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/28 21:52:16 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			init_buffer(t_terminf *shell_env)
{
	if (!(shell_env->line_buffer = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			handle_buffer(t_terminf *shell_env)
{

}
