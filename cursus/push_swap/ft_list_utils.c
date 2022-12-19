/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:30:15 by pbengoec          #+#    #+#             */
/*   Updated: 2022/12/19 20:21:17 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **a, int num)
{
	t_stack	*first;
	t_stack	*second;

	if (a[0] && a[0]->next)
	{
		first = a[0];
		second = first->next;
		first->next = first->next->next;
		second->next = first;
		a[0] = second;
	}
	if (num == 0)
		ft_putstr_fd("sa\n", 1);
	else if (num == 1)
		ft_putstr_fd("sb\n", 1);
	else if (num == 2)
		ft_putstr_fd("ss\n", 1);
}

int	ft_list_size(t_stack **a)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = a[0];
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	ft_reverse_rotate(t_stack **a, int num)
{
	t_stack	*temp;
	t_stack	*last;

	if (a[0])
	{
		last = a[0];
		while (last->next)
		{
			last = last->next;
		}
		if (a[0] == last)
			return ;
		if (a[0]->next == last)
		{
			ft_swap(a, 10);
			return ;
		}
		temp = a[0];
		a[0] = a[0]->next;
		last->next = temp;
		temp->next = NULL;
	}
	if (num == 0)
		ft_putstr_fd("ra\n", 1);
	else if (num == 1)
		ft_putstr_fd("rb\n", 1);
	else if (num == 2)
		ft_putstr_fd("r\n", 1);
}

void	ft_rotate(t_stack **a, int num)
{
	t_stack	*last;
	t_stack	*index;
	t_stack	*temp;

	if (a[0])
	{
		last = a[0];
		while (last->next)
		{
			index = last;
			last = last->next;
		}
		if (a[0] == last)
			return ;
		if (a[0]->next == last)
		{
			ft_swap(a, 0);
			return ;
		}
			temp = a[0];
			a[0] = last;
			a[0]->next = temp;
			index->next = NULL;
	}
	if (num == 0)
		ft_putstr_fd("rra\n", 1);
	else if (num == 1)
		ft_putstr_fd("rrb\n", 1);
	else if (num == 2)
		ft_putstr_fd("rr\n", 1);
}

void	ft_push_list(t_stack **a, t_stack **b, int num)
{
	t_stack	*push;
	t_stack	*tmp;

	if (a[0])
	{
		push = a[0];
		tmp = b[0];
		a[0] = a[0]->next;
		b[0] = push;
		push->next = tmp;
	}
	if (num == 0)
		ft_putstr_fd("pa\n", 1);
	else if (num == 1)
		ft_putstr_fd("pb\n", 1);
}
