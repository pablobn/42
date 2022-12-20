/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:46:46 by pbengoec          #+#    #+#             */
/*   Updated: 2022/12/20 19:30:48 by pbengoec         ###   ########.fr       */
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
		printf("\nPosition %d Move %d Other Move %d Dir %d Calculo %d\n", a->position, a->move, a->other_move,a->dir, a->calc);
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

void	ft_give_other_number(t_stack *a, t_stack *b)
{
	int	min;
	int max;

	min = 2147483647;
	max = 2147483647;
	while (a)
	{
		if (a->position > b->position && a->position < min && !b->find)
		{
			b->calc = a->move + b->move;
			b->other_dir = a->dir;
			b->other_move = a->move;
			if (a->dir == b->dir)
			{
				if (a->move >= b->move)
					b->calc = a->move;
				else
					b->calc = b->move;
			}
			min = a->position;
		}
		if (a->position < b->position && a->position < max && b->find)
		{
			b->calc = a->move + b->move;
			b->other_dir = a->dir;
			b->other_move = a->move;
			if (a->dir == b->dir)
			{
				if (a->move >= b->move)
					b->calc = a->move;
				else
					b->calc = b->move;
			}
			max = a->position;
		}
		a = a->next;
	}
	if (min == 2147483647)
		b->find = 1;
}

void	ft_calcular_movimientos(t_stack **a, t_stack *b)
{
	while (b)
	{
		b->find = 0;
		b->calc = 0;
		b->other_move = 0;
		ft_give_other_number(a[0], b);
		if (b->find)
			ft_give_other_number(a[0], b);
		b = b->next;
	}
}
