/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:11:58 by pbengoec          #+#    #+#             */
/*   Updated: 2023/02/23 20:29:59 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	atexit(leaks);
	if (argc == 2)
	{
		if (ft_start(argv[1]))
			return (255);
	}
	return (0);
}
