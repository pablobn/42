/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:37:08 by pbengoec          #+#    #+#             */
/*   Updated: 2022/12/17 20:47:00 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_list(t_stack **a)
{
	t_stack	*c;
	int		i;
	int		flag;

	i = 0;
	c = a[0];
	flag = 1;
	while (c)
	{
		if (c->position != i)
			flag = 0;
		i++;
		c = c->next;
	}
	if (flag)
		return (1);
	return (0);
}

void	ft_ord_three(t_stack **a, int num)
{
	t_stack	*c;

	c = a[0];
	if (c->position > c->next->position
		&& c->position > c->next->next->position)
		ft_reverse_rotate(&c, num);
	else if (c->next->position > c->position
		&& c->next->position > c->next->next->position)
		ft_rotate(&c, num);
	if (c->position > c->next->position)
		ft_swap(&c, num);
	a[0] = c;
}

void	ft_move_positions(t_stack **a, t_stack **b)
{
	int		min;
	t_stack	*c;
	t_stack	*pos;

	c = b[0];
	pos = c;
	min = c->calc;
	while (c)
	{
		if (c->calc < min)
		{
			min = c->calc;
			pos = c->current;
		}
	}
	if (pos->other->dir == pos->dir)
	{
		if (pos->dir == 0)
		{
			if (pos->dir > pos->other->dir)
			{
				while (pos->move > 0)
				{
					if (pos->other->move > 0)
						ft_rotate(b, 2);
					else
						ft_rotate(b, 1);
					pos->move = pos->move - 1;
				}
			}
		}
	}
}

void	ft_push_swap(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	ft_give_index(a);
	while (ft_list_size(a) > 3)
	{
		ft_give_current_place(a[0]);
		ft_push_list(a, &b, 0);
		ft_give_current_place(b);
	}
	ft_ord_three(a, 0);
	ft_give_current_place(a[0]);
	ft_calcular_movimientos(a, b);
	while (ft_list_size(&b))
	{
		ft_move_positions(a, &b);
		ft_push_list(&b, a, 1);
		ft_give_current_place(a[0]);
		ft_give_current_place(b);
		ft_calcular_movimientos(a, b);
	}
	printf("LISTA FINAL A");
	show_node(a[0]);
	printf("LISTA FINAL B");
	show_node(b);
}
