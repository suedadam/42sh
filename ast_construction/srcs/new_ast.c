/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 22:15:19 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/21 22:16:17 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast		*new_ast(void)
{
	if (!(ast = (t_ast *)ft_memalloc(sizeof(t_ast))))
		return (NULL);
	ast->token = 0;
	ast->type = 0;
	ast->left_child = 0;
	ast->right_child = 0;
	return (ast);
}
