/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_defs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:45:18 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/09 15:49:50 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maincontrol.h"

int		(*multibyte_jump[])(char byte) = {
	ft_linemove,
	ft_delete,
	ft_shift,
	ft_alt,
	ft_scroll,
	ft_history,
	ft_page
};

int		(*control_jump[])() = {
	control_a,
	NULL,
	NULL,
	NULL,
	control_e,
	NULL,
	control_c,
	control_h,
	NULL,
	control_j,
	control_k,
	control_l,
	control_m,
	NULL,
	control_o,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	control_u,
	control_v,
	control_w,
	NULL,
	control_y,
};