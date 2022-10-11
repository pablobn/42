/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:42:29 by pbengoec          #+#    #+#             */
/*   Updated: 2022/10/11 15:59:17 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		contador;

	contador = 0;
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_switch(*format, list, &contador);
		}
		else
		{
			ft_putchar_fd(*format, 1, &contador);
		}
		format++;
	}
	va_end(list);
	return (contador);
}
