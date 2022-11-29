/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:43:41 by pbengoec          #+#    #+#             */
/*   Updated: 2022/11/29 17:44:30 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_node(t_stack **stack, int dato)
{
	t_stack	*new;
	new = malloc(sizeof(t_stack));
	new->value = dato;
	new->next = *stack;
	*stack = new;
}

int	main()
{
	t_stack *a = NULL;
	t_stack *b = NULL;
	int i;

	i = 5;
	insert_node(&a, 53);
	printf("%d\n", a->value);
	insert_node(&b, 234);
	printf("%d\n", b->value);
	return (0);
}