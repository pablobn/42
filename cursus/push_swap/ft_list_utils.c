/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:30:15 by pbengoec          #+#    #+#             */
/*   Updated: 2023/01/12 14:32:47 by pbengoec         ###   ########.fr       */
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

static void	ft_print_reverse_rotate(int num)
{
	if (num == 0)
		ft_putstr_fd("ra\n", 1);
	else if (num == 1)
		ft_putstr_fd("rb\n", 1);
	else if (num == 2)
		ft_putstr_fd("rr\n", 1);
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
			ft_swap(a, num);
			return ;
		}
		temp = a[0];
		a[0] = a[0]->next;
		last->next = temp;
		temp->next = NULL;
	}
	ft_print_reverse_rotate(num);
}

static void	ft_print_rotate(int num)
{
	if (num == 0)
		ft_putstr_fd("rra\n", 1);
	else if (num == 1)
		ft_putstr_fd("rrb\n", 1);
	else if (num == 2)
		ft_putstr_fd("rrr\n", 1);
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
			ft_swap(a, num);
			return ;
		}
			temp = a[0];
			a[0] = last;
			a[0]->next = temp;
			index->next = NULL;
	}
	ft_print_rotate(num);
}
