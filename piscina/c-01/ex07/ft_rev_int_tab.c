/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:37:43 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/18 19:42:49 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i++;
	}
}

int main(){
	int tab[3];
	tab[0] = 1;
	tab[1] = 2;
	int *ptr;

	ptr = tab;
	printf("%d",ptr[1]);
	
}
