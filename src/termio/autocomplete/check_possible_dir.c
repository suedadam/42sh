/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_possible_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:28:19 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/16 02:11:39 by tle-huu-         ###   ########.fr       */
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
	if (len && (g_shell_env.cursor.buffer[(len - 1)] == '/'))
	{
		temp = end_word_debut();
		if (!(dir = ft_strchr(temp, '/')) || !(*dir))
			return (NULL);
		len = (dir - temp) + 1;
		if (!(dir = (char *)ft_memalloc(sizeof(char) * len + 1)))
			return (NULL);
		if (!(ft_strncpy(dir, temp, len)))
		{
			meta_free(dir);
			return (NULL);
		}
		return (dir);
	}
	return (NULL);
}
