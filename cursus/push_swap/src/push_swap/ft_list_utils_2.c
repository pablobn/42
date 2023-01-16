/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:46:46 by pbengoec          #+#    #+#             */
/*   Updated: 2023/01/13 10:23:36 by pbengoec         ###   ########.fr       */
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

void	ft_order_array(int *ar, int size)
{
	int	ord;
	int	i;
	int	swap;

	ord = 1;
	while (ord)
	{
		ord = 0;
		i = 0;
		while (i < size)
		{
			if (ar[i] > ar[i + 1])
			{
				swap = ar[i];
				ar[i] = ar[i + 1];
				ar[i + 1] = swap;
				ord = 1;
			}
			i++;
		}
	}
}

void	ft_order_list(t_stack **a, int *ar)
{
	t_stack	*c;
	int		i;
	int		flag;

	i = 0;
	c = a[0];
	while (i < ft_list_size(a))
	{
		flag = 1;
		while (c && flag)
		{
			if (c->value == ar[i])
			{
				c->position = i;
				flag = 0;
			}
			c = c->next;
		}
		c = a[0];
		i++;
	}
}

void	ft_give_index(t_stack **a)
{
	t_stack	*c;
	int		*ar;
	int		i;

	ar = malloc(sizeof(int) * ft_list_size(a) + 1);
	if (!ar)
		return ;
	i = 0;
	c = a[0];
	while (c)
	{
		ar[i] = c->value;
		c = c->next;
		i++;
	}
	ar[i] = '\0';
	ft_order_array(ar, ft_list_size(a) - 1);
	ft_order_list(a, ar);
	free(ar);
}
