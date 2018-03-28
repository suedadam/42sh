/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:24:14 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/27 20:35:44 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

int main(int argc, char **argv) {


	t_token_type *type = ft_memalloc(sizeof(t_token_type) * 13);
	type[0] = 0;
	type[1] = 0;
	type[2] = 1;
	type[5] = 1;

	// type[0] = 0;
	// type[1] = 0;
	// type[2] = 0;
	// type[3] = 1;
	// type[4] = 0;
	// type[5] = 0;
	// type[6] = 1;
	// type[7] = 0;
	// type[8] = 0;
	// type[9] = 1;
	// type[10] = 0;
	// type[11] = 0;
	// type[12] = 0;

	// int i = 0;
	// while (i < argc - 1)
	// {
	// 	argv[i] = argv[i + 1];
	// 	i++;
	// }
	// argv[argc - 1] = 0;

	t_queue *forest = build_forest(argv + 1, (t_token_type *)type);
	run_forest((t_ast **)&(forest->head->content));
	printf("PUTUUUHH\n");
	// while (vasy)
	// {

	// 	printf("\nnew tree\n\n");
	// 	print_ast((t_ast *)(forest->head->content), 0);
	// 	vasy = vasy->next;
	// }
	while(1);
	return 0;
}
