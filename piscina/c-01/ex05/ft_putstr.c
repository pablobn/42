/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:59:10 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/23 14:05:49 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

void	ft_putstr(char *str)
{
	int i;
	char a;
	
	i = 0;
	while (str[i] != '\0')
	{
		a = str[i];
		write(1, &a, 1);
		i++;
	}
}

int	main(){
	char *str = "hola que tal estas";
	ft_putstr(str);
	return 0;
}