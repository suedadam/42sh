/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linefeed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:52:17 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/05 11:52:26 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			ft_linefeed(void)
{
	int		ret;

	ret = EXIT_SUCCESS;
	ret = reset_buffer();
	if (ret == EXIT_SUCCESS)
		reset_prompt();
	// history_handler
	// satkins_parser(shell_env->line_buffer);
	// reset the buffer
	return (ret);
}