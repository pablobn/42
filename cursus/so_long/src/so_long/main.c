/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:11:58 by pbengoec          #+#    #+#             */
/*   Updated: 2023/03/01 18:00:55 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	int	i;

	atexit(leaks);
	i = 0;
	if (argc == 2)
	{
		i = ft_strlen(argv[1]) - 4;
		if (ft_strncmp(&argv[1][i], ".ber", 4) != 0)
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("El archivo no es .ber\n", 2);
			return (255);
		}
		if (ft_start(argv[1]))
			return (255);
	}
	return (0);
}
