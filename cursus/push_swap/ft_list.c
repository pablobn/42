/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:46:46 by pbengoec          #+#    #+#             */
/*   Updated: 2022/12/19 16:31:36 by pbengoec         ###   ########.fr       */
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

void	show_node(t_stack *a)
{
	int	i;

	i = 0;
	printf("\n-------------");
	while (a)
	{
		printf("\nValue %d Current %d Position %d Move %d Other Move %d Dir %d Calculo %d\n", a->value, a->current, a->position, a->move, a->other_move,a->dir, a->calc);
		a = a->next;
		i++;
	}
	printf("-------------\n");
}

void	ft_give_current_place(t_stack *a)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = ft_list_size(&a);
	ft_give_direction(&a);
	while (a)
	{
		a->current = i;
		a->move = j;
		a = a->next;
		i++;
		if (i > size / 2)
		{
			if (size % 2 == 0 || i - 1 != size / 2)
				j--;
		}
		else
			j++;
	}
}

void	ft_give_direction(t_stack **c)
{
	t_stack	*a;
	int		size;
	int		i;

	a = c[0];
	size = ft_list_size(&a);
	i = 0;
	while (a)
	{
		if (i > size / 2)
			a->dir = 0;
		else
			a->dir = 1;
		a = a->next;
		i++;
	}
}

void	ft_calcular_movimientos(t_stack **a, t_stack *b)
{
	int		calc;
	int		min;
	t_stack	*c;

	while (b)
	{
		calc = b->move;
		b->other_move = -1;
		min = 2147483647;
		c = a[0];
		while (c)
		{
			if (c->position > b->position && c->position < min)
			{
				calc = c->move + b->move;
				b->other_dir = c->dir;
				b->other_move = c->move;
				if (c->dir == b->dir)
				{
					if (c->move >= b->move)
						calc = c->move;
					else
						calc = b->move;
				}
				min = c->position;
			}
			c = c->next;
		}
		b->calc = calc;
		b = b->next;
	}
}
