/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 11:25:38 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 15:29:31 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hangingbyte.h"
#include "ft_proto.h"

int		quote_mode(void)
{
	if (T_QUOTE)
	{
		if (drop_prompt("quote> ") == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (T_DQUOTE)
	{
		if (drop_prompt("dquote> ") == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	get_cursor_first_position();
	return (EXIT_SUCCESS);
}
