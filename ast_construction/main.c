/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:24:14 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/26 16:57:53 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ast.h"

int main(int argc, char **argv) {
	printf("salut\n");

	t_token_type type[8] = {0, 0, 0, 1, 0, 1, 0, 0};

	int i = 0;
	while (i < argc - 1)
	{
		argv[i] = argv[i + 1];
		i++;
	}
	argv[argc - 1] = 0;

	printf("ici : %s %s %s %s\n", argv[0], argv[1], argv[2], argv[3]);
	t_queue *forest = build_forest(argv, (t_token_type *)type);
	while (!(queue_empty(forest)))
	{

		printf("\nnew tree\n\n");
		print_ast((t_ast *)(forest->head->content), 0);
		queue_pop(forest);
	}
	while(1);
	return 0;
}
