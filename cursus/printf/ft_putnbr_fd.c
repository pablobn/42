/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:14:19 by pbengoec          #+#    #+#             */
/*   Updated: 2022/10/10 15:26:12 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd, int *cont)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd, cont);
	else if (n >= 0 && n <= 9)
		ft_putchar_fd(n + 48, fd, cont);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd, cont);
		n = -n;
		ft_putnbr_fd(n, fd, cont);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd, cont);
		ft_putchar_fd(n % 10 + '0', fd, cont);
	}
}
