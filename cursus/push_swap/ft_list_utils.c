/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:30:15 by pbengoec          #+#    #+#             */
/*   Updated: 2022/12/14 17:38:33 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **a)
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
	printf("s\n");
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

void	ft_reverse_rotate(t_stack **a)
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
			ft_swap(a);
			return ;
		}
		temp = a[0];
		a[0] = a[0]->next;
		last->next = temp;
		temp->next = NULL;
	}
	printf("rr\n");
}

void	ft_rotate(t_stack **a)
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
			ft_swap(a);
			return ;
		}
			temp = a[0];
			a[0] = last;
			a[0]->next = temp;
			index->next = NULL;
	}
	printf("r\n");
}

void	ft_push_list(t_stack **a, t_stack **b)
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
}
