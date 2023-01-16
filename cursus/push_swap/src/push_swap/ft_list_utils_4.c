/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:19:21 by pbengoec          #+#    #+#             */
/*   Updated: 2023/01/13 10:23:45 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_give_max(t_stack *a)
{
	t_stack	*max;

	max = a;
	while (a)
	{
		if (a->position > max->position)
			max = a;
		a = a->next;
	}
	max->max = 1;
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

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
