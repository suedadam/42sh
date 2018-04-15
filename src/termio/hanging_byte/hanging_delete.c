/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanging_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:01:45 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/14 21:28:10 by asyed            ###   ########.fr       */
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
		if (temp != g_shell_env.buffer->buff && *(temp - 1) == '|')
			T_PIPE ? (T_PIPE = 0) : (T_PIPE = 1);
	}
	else if (paren_delete(*byte) == EXIT_SUCCESS)
		return ;
	else if (curly_delete(*byte) == EXIT_SUCCESS)
		return ;
}
