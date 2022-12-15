/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:37:08 by pbengoec          #+#    #+#             */
/*   Updated: 2022/12/15 20:21:22 by pbengoec         ###   ########.fr       */
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

void	ft_ord_three(t_stack **a)
{
	t_stack	*c;

	c = a[0];
	if (c->position - 1 == c->next->position)
		ft_swap(&c);
	if (c->position - 1 > c->next->position)
		ft_reverse_rotate(&c);
	if (c->next->position > c->next->next->position)
		ft_rotate(&c);
	a[0] = c;
}

void	ft_push_swap(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	ft_give_index(a);
	while (!valid_list(a))
	{
		show_node(a[0]);
		if (ft_list_size(a) <= 3)
			ft_ord_three(a);
		else
			break ;
	}
	printf("\nLISTA FINAL\n\n");
	show_node(a[0]);
}
