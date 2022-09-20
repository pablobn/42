/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:38:03 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/29 16:21:31 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48);
	}
	else if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
		ft_putnbr(nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}
