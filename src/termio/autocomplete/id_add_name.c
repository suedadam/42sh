/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_add_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:07:32 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/13 16:07:51 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"
#include "ft_proto.h"

int		id_add_name(struct stat *sbuf, struct dirent *entry)
{
	size_t	len;
	char	*send;

	len = ft_strlen(entry->d_name);
	if (!(send = ft_memalloc(len + 2)))
		return (EXIT_FAILURE);
	ft_strcpy(send, entry->d_name);
	if (S_ISLNK(sbuf->st_mode))
		ft_strcat(send, "@");
	else if (S_ISDIR(sbuf->st_mode))
		ft_strcat(send, "/");
	else if (S_IXUSR & sbuf->st_mode)
		ft_strcat(send, "*");
	//send to trie
	return (EXIT_SUCCESS);
}
