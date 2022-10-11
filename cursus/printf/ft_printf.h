/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:38:49 by pbengoec          #+#    #+#             */
/*   Updated: 2022/10/11 15:59:55 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

void	ft_putstr_fd(char *s, int fd, int *cont);
void	ft_putchar_fd(char c, int fd, int *cont);
void	ft_switch(char c, va_list list, int *cont);
int		ft_printf(char const *format, ...);
void	ft_putnbr_fd(int n, int fd, int *cont);
void	ft_putnbr_fd_unsigned(unsigned int n, int fd, int *cont);
void	ft_conver_hexa(unsigned long int num, char c, int *cont);
#endif