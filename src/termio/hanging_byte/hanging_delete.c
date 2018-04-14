/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanging_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:01:45 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/13 22:03:07 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hangingbyte.h"
#include "ft_proto.h"

void		hanging_delete(char *byte)
{
	char	*temp;

	temp = byte;
	if (*byte == '\'' && !T_DQUOTE)
		T_QUOTE = (T_QUOTE == 1) ? 0 : 1;
	else if (*byte == '\"' && !T_QUOTE)
		T_DQUOTE = (T_DQUOTE == 1) ? 0 : 1;
	else if (g_shell_env.cursor.position) 
	{
		while ((temp != g_shell_env.buffer->buff)
				&& IS_WHITESPACE(*(temp - 1)))
			temp--;
		if (*(temp - 1) == '|')
			T_PIPE ? (T_PIPE = 0) : (T_PIPE = 1);
	}
	else if (paren_delete(*byte) == EXIT_SUCCESS)
		return ;
	else if (curly_delete(*byte) == EXIT_SUCCESS)
		return ;
}
