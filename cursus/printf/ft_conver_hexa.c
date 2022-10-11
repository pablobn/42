/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:22:18 by pbengoec          #+#    #+#             */
/*   Updated: 2022/10/11 15:57:11 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conver_hexa(unsigned long int num, char c, int *cont)
{
	if (num >= 0 && num <= 9)
		ft_putchar_fd(num + 48, 1, cont);
	else if (num >= 10 && num < 16)
		ft_putchar_fd(num + c - 10, 1, cont);
	else if (num < 0)
	{
		ft_putchar_fd('-', 1, cont);
		num = -num;
		ft_conver_hexa(num, c, cont);
	}
	else
	{
		ft_conver_hexa(num / 16, c, cont);
		if (num % 16 >= 0 && num % 16 <= 9)
			ft_putchar_fd(num % 16 + 48, 1, cont);
		else
			ft_putchar_fd(num % 16 + c - 10, 1, cont);
	}
}
