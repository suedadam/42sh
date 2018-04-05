/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_return.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:50:14 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/04 20:23:53 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
/*
int			ft_carriage_dispatch(char byte)
{

}
*/
int			ft_carriage_return(void)
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
