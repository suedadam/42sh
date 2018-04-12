/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:57:20 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/14 15:22:50 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack				*init_stack(void)
{
	t_stack			*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->top = NULL;
	return (node);
}

void				ft_stackpush(t_stack *stack, void *content, size_t c_size)
{
	t_node			*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->content = ft_memalloc(c_size);
	node->content = ft_memmove(node->content, content, c_size);
	node->next = stack->top;
	stack->top = node;
}

void				*ft_stackpop(t_stack *stack)
{
	t_node			*next;
	void			*anything;

	if (stack->top == NULL)
		return (NULL);
	next = stack->top->next;
	anything = stack->top->content;
	free(stack->top);
	stack->top = next;
	return (anything);
}

void				*ft_stackpeak(t_stack *stack)
{
	if (stack->top == NULL)
		return (NULL);
	return (stack->top->content);
}

int					isempty_stack(t_stack *stack)
{
	return (stack->top == NULL);
}
