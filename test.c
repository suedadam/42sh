/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:32:39 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/21 20:31:46 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct		s_ast
{
	t_token				*token_array;
	struct s_ast		*left_child;
	struct s_ast		*right_child;
}					t_ast;

typedef struct		s_token
{
	char 				*token;
	enum token_type		type;

}					t_token;
