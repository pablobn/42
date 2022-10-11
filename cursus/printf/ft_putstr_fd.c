/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:05:09 by pbengoec          #+#    #+#             */
/*   Updated: 2022/10/11 16:07:32 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, int *cont)
{
	int	i;

	if (s == NULL)
	{
		*cont += 6;
		write(fd, "(null)", 6);
	}
	else
	{
		i = 0;
		while (s[i])
		{
			ft_putchar_fd(s[i], fd, cont);
			i++;
		}	
	}
}
