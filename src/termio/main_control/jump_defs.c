/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_defs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:45:18 by nkouris           #+#    #+#             */
/*   Updated: 2018/04/15 20:55:31 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maincontrol.h"
#include "ft_proto.h"

int		(*g_multibyte_jump[])(char byte) = {
	ft_linemove,
	ft_delete,
	ft_shift,
	ft_alt,
	ft_scroll,
	ft_history,
	ft_page
};

int		(*g_control_jump[])() = {
	control_a,
	NULL,
	NULL,
	NULL,
	control_e,
	NULL,
	control_c,
	control_h,
	start_autocomplete,
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
	NULL,
};
