/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_figures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:25:00 by pbengoec          #+#    #+#             */
/*   Updated: 2023/03/01 12:27:30 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_send_msg(t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	if (game[0].e > 1 || game[0].p > 1)
		ft_putstr_fd("Salida o posición estan duplicados\n", 2);
	if (game[0].e == 0 || game[0].p == 0 || game[0].c == 0)
		ft_putstr_fd("Faltan carácteres obligatorios\n", 2);
}
