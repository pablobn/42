/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:10:38 by pbengoec          #+#    #+#             */
/*   Updated: 2022/10/11 16:07:23 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_switch(char c, va_list list, int *cont)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(list, int), 1, cont);
	else if (c == '%')
		ft_putchar_fd('%', 1, cont);
	else if (c == 's')
		ft_putstr_fd(va_arg(list, char *), 1, cont);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(list, int), 1, cont);
	else if (c == 'u')
		ft_putnbr_fd_unsigned(va_arg(list, unsigned int), 1, cont);
	else if (c == 'x' || c == 'X')
		ft_conver_hexa(va_arg(list, unsigned int), c - 23, cont);
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1, cont);
		ft_conver_hexa(va_arg(list, unsigned long int), 'a', cont);
	}
}
