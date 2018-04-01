/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_return.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:50:14 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/31 17:43:35 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int			ft_carriage_return(void)
{
	int		ret;

	slash_token = (int)byte;

	ret = EXIT_SUCCESS;
	ret = reset_buffer();
	if (ret == EXIT_SUCCESS)
		reset_prompt();
	// history_handler
	// satkins(shell_env->line_buffer);
	// reset the buffer
	return (ret);
}
