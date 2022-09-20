/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:38:38 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/20 16:14:17 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	check;
	int	tmp;

	check = 0;
	while (check == 0)
	{
		i = 0;
		check = 1;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				check = 0;
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
	}
}
