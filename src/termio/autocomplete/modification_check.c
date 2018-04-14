/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modification_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 01:35:33 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/14 02:13:22 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_autocomplete.h"
#include "ft_proto.h"

int		modification_check(char *check)
{
	struct stat	sbuf;

	if (!(*check))
		lstat(".", sbuf);
}
