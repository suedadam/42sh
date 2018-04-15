/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_possible_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:28:19 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/15 15:49:14 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"
#include "ft_proto.h"

char	*check_possible_dir(void)
{
	char	*dir;
	char	*temp;
	size_t	len;

	dir = NULL;
	len = g_shell_env.cursor.position;
	printf("check for possible dir\n");
	if (len && (g_shell_env.cursor.buffer[(len - 1)] == '/'))
	{
		temp = end_word_debut();
		while (temp != g_shell_env.buffer->buff	&& !IS_WHITESPACE(*(temp - 1)))
			temp--;
		dir = ft_strchr(temp, '/');
		len = (dir - temp) + 1;
		if (!(dir = (char *)ft_memalloc(sizeof(char) * len)))
			return (NULL);
		if (!(ft_strncpy(dir, temp, len)))
		{
			meta_free(dir);
			return (NULL);
		}
		temp = concatpath(dir, "./");
		meta_free(dir);
		printf("is possible\n");
		return (temp);
	}
	return (NULL);
}
