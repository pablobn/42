/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:37:08 by pbengoec          #+#    #+#             */
/*   Updated: 2022/12/19 18:28:56 by pbengoec         ###   ########.fr       */
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

void	ft_change_positions(t_stack **a, int dir, int move, int num)
{
	while (move > 0)
	{
		if (dir == 0)
			ft_rotate(a, num);
		else
			ft_reverse_rotate(a, num);
		move--;
	}
}

void	ft_move_positions(t_stack **a, t_stack **b)
{
	int		min;
	int		dif;
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
			pos = c;
		}
		c = c->next;
	}
	if (pos->dir == pos->other_dir)
	{
		if (pos->dir > pos->other_dir)
		{
			dif = pos->move - pos->other_move;
			ft_change_positions(b, pos->dir, pos->move - dif, 2);
			ft_change_positions(a, pos->other_dir, pos->other_move, 5);
			ft_change_positions(b, pos->dir, dif, 1);
		}
		else
		{
			dif = pos->other_move - pos->move;
			ft_change_positions(b, pos->dir, pos->move, 5);
			ft_change_positions(a, pos->other_dir, pos->other_move - dif, 2);
			ft_change_positions(a, pos->other_dir, dif, 0);
		}
	}
	else
	{
		ft_change_positions(b, pos->dir, pos->move, 1);
		ft_change_positions(a, pos->other_dir, pos->other_move, 0);
	}
}

void	ft_push_swap(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (ft_list_size(a) <= 2)
	{
		if (ft_list_size(a) == 2)
			if (a[0]->value > a[0]->next->value)
				ft_swap(a, 0);
		return ;
	}
	ft_give_index(a);
	while (ft_list_size(a) > 3)
	{
		ft_give_current_place(a[0]);
		ft_push_list(a, &b, 1);
		ft_give_current_place(b);
	}
	ft_ord_three(a, 0);
	ft_give_current_place(a[0]);
	ft_calcular_movimientos(a, b);
	while (ft_list_size(&b))
	{
		ft_move_positions(a, &b);
		ft_push_list(&b, a, 0);
		if (a[0]->other_move == -1)
			ft_reverse_rotate(a, 0);
		ft_give_current_place(a[0]);
		ft_give_current_place(b);
		ft_calcular_movimientos(a, b);
	}
	// while (!valid_list(a))
	// {
	// 	if (ft_list_size(a) / 2 >= a[0]->position)
	// 		ft_rotate(a, 0);
	// 	else
	// 		ft_reverse_rotate(a, 0);
	// }
	printf("LISTA FINAL A");
	show_node(a[0]);
	printf("LISTA FINAL B");
	show_node(b);
}
