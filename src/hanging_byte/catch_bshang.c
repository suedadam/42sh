/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_bshang.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:01:21 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/10 15:05:13 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hangingbyte.h"
#include "ft_proto.h"

int		catch_bshang(char byte)
{
	if (byte == '\\')
		return (drop_prompt("> "));
	hanging_byte(byte);
	return (EXIT_SUCCESS);
}
