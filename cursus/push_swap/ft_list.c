/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:46:46 by pbengoec          #+#    #+#             */
/*   Updated: 2022/12/05 21:14:01 by pbengoec         ###   ########.fr       */
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

int	repetitive_node(t_stack **stack, int dato)
{
	t_stack	*a;

	a = stack[0];
	while (a)
	{
		if (a->value == dato)
			return (1);
		a = a->next;
	}
	return (0);
}

void	show_node(t_stack *a)
{
	if (a == NULL)
		return ;
	// printf("%d\n", a->value);
	show_node(a->next);
}
