/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:37:08 by pbengoec          #+#    #+#             */
/*   Updated: 2023/01/12 14:54:21 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_change_positions(t_stack **a, int dir, int move, int num)
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

static void	ft_move_positions(t_stack *pos, t_stack **a, t_stack **b, int dif)
{
	if (pos->dir == pos->other_dir)
	{
		if (pos->move > pos->other_move)
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

void	ft_move_less_movement(t_stack **a, t_stack **b)
{
	int		min;
	int		dif;
	t_stack	*c;
	t_stack	*pos;

	c = b[0];
	pos = c;
	min = c->calc;
	dif = 0;
	while (c)
	{
		if (c->calc < min)
		{
			min = c->calc;
			pos = c;
		}
		c = c->next;
	}
	ft_move_positions(pos, a, b, dif);
}

static void	ft_push_b_to_a(t_stack **a, t_stack *b)
{
	ft_ord_three(a, 0);
	ft_give_current_place(a[0]);
	ft_calculate_movements(a, b);
	while (ft_list_size(&b))
	{
		ft_move_less_movement(a, &b);
		ft_push_list(&b, a, 0);
		ft_give_current_place(a[0]);
		ft_give_current_place(b);
		ft_calculate_movements(a, b);
	}
	while (!ft_valid_list(a))
	{
		if (ft_list_size(a) / 2 >= a[0]->position)
			ft_rotate(a, 0);
		else
			ft_reverse_rotate(a, 0);
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
	ft_give_max(a[0]);
	if (ft_valid_list(a))
		return ;
	while (ft_list_size(a) > 3)
	{
		ft_give_current_place(a[0]);
		ft_push_list(a, &b, 1);
		ft_give_current_place(b);
	}
	ft_push_b_to_a(a, b);
}
