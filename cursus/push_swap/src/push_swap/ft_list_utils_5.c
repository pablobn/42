/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:50:53 by pbengoec          #+#    #+#             */
/*   Updated: 2023/01/16 13:18:40 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_valid_list(t_stack **a)
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

void	free_list(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}