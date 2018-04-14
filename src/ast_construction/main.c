/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:24:14 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/04/13 23:41:58 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

int main(int argc, char **argv) {


	t_token_type *type = malloc(sizeof(t_token_type) * 13);
	type[0] = 1;
	type[1] = 1;
	type[2] = 2;
	type[3] = 1;
	type[4] = 1;
	type[5] = 1;
	type[6] = 1;
	type[7] = 1;
	type[8] = 1;
	type[9] = 1;
	type[10] = 1;
	type[11] = 1;
	type[12] = 0;

	int i = 0;
	t_queue *forest = build_forest(argv + 1, (t_token_type *)type);
	if (!forest)
	{
		printf("poop\n");
		return (EXIT_FAILURE);
	}
	t_node *vasy = forest->first;
	while (vasy)
	{

		printf("\nnew tree\n\n");
		print_ast((t_ast *)(vasy->content), 0);
		vasy = vasy->next;
	}
	run_forest(forest);
	printf("Puthhh\n");
	// while(1);
	return 0;
}
