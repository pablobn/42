/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:13:36 by pbengoec          #+#    #+#             */
/*   Updated: 2022/10/10 15:31:38 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_unsigned(unsigned int n, int fd, int *cont)
{
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + 48, fd, cont);
	else if (n < 0)
	{
		n = -n;
		ft_putnbr_fd_unsigned(n, fd, cont);
	}
	else
	{
		ft_putnbr_fd_unsigned(n / 10, fd, cont);
		ft_putchar_fd(n % 10 + '0', fd, cont);
	}
}
