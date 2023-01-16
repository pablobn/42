/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:17:30 by pbengoec          #+#    #+#             */
/*   Updated: 2023/01/13 10:23:42 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_is_position_smaller(t_stack **b, t_stack **a, int *min)
{
	if (a[0]->position > b[0]->position && a[0]->position < *min && !b[0]->find)
	{
		b[0]->calc = a[0]->move + b[0]->move;
		b[0]->other_dir = a[0]->dir;
		b[0]->other_move = a[0]->move;
		if (a[0]->dir == b[0]->dir)
		{
			if (a[0]->move >= b[0]->move)
				b[0]->calc = a[0]->move;
			else
				b[0]->calc = b[0]->move;
		}
		*min = a[0]->position;
	}
}

static void	ft_is_position_bigger(t_stack **b, t_stack **a, int *max)
{
	if (a[0]->position < b[0]->position && a[0]->position < *max && b[0]->find)
	{
		b[0]->calc = a[0]->move + b[0]->move;
		b[0]->other_dir = a[0]->dir;
		b[0]->other_move = a[0]->move;
		if (a[0]->dir == b[0]->dir)
		{
			if (a[0]->move >= b[0]->move)
				b[0]->calc = a[0]->move;
			else
				b[0]->calc = b[0]->move;
		}
		*max = a[0]->position;
	}
}

static void	ft_give_other_number(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = 2147483647;
	max = 2147483647;
	while (a)
	{
		ft_is_position_smaller(&b, &a, &min);
		ft_is_position_bigger(&b, &a, &max);
		a = a->next;
	}
	if (min == 2147483647)
		b->find = 1;
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

void	ft_calculate_movements(t_stack **a, t_stack *b)
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
