/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 13:51:22 by nkouris           #+#    #+#             */
/*   Updated: 2017/09/29 01:19:35 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num(int p)
{
	int len;

	len = 0;
	if (p < 0)
	{
		len++;
		p = (p * -1);
	}
	else if (p == 0)
		return (1);
	while (p != 0)
	{
		p = p / 10;
		len++;
	}
	return (len);
}

static int	find_sign(int o)
{
	if (o < 0)
		return (1);
	else
		return (0);
}

char		*ft_itoa(int n)
{
	int		length;
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = count_num(n);
	result = ft_strnew(length);
	if (!result)
		return (0);
	else if (n == 0)
		result[0] = '0';
	if (find_sign(n))
	{
		result[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		result[--length] = ((n % 10) + '0');
		n = (n - (n % 10)) / 10;
	}
	return (result);
}
