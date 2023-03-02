/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:39:49 by pbengoec          #+#    #+#             */
/*   Updated: 2023/03/02 17:38:42 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_map_rectangle(t_map *map)
{
	int		i;
	int		num;
	char	*line;

	num = len_map_line(map, 1);
	if (len_map(map, 1) == num)
		return (1);
	while (map)
	{
		i = 0;
		line = map->line;
		while (*line)
		{
			if (*line != '\n')
				i += 1;
			line++;
		}
		if (i != num)
			return (1);
		map = map->next;
	}
	return (0);
}

static int	ft_check_figures(t_game *game, t_map *map)
{
	char	*line;

	while (map)
	{
		line = map->line;
		while (*line)
		{
			if (*line == 'C')
				game[0].c += 1;
			if (*line == 'P')
				game[0].p += 1;
			if (*line == 'E')
				game[0].e += 1;
			line++;
		}
		map = map->next;
	}
	if (game[0].e == 0 || game[0].p == 0 || game[0].c == 0)
		return (1);
	if (game[0].e > 1 || game[0].p > 1)
		return (1);
	return (0);
}

static int	ft_wall_rodated(t_map *map)
{
	char	*line;

	while (map)
	{
		line = map->line;
		if (*line != '1')
			return (1);
		while (*line)
			line++;
		line--;
		line--;
		if (*line != '1')
			return (1);
		map = map->next;
	}
	return (0);
}

static int	ft_check_numbers(t_map *map)
{
	char	*line;

	while (map)
	{
		line = map->line;
		while (*line)
		{
			if (*line != '0' && *line != 'P' && *line != 'C'
				&& *line != 'E' && *line != '1' && *line != '\n')
				return (1);
			line++;
		}
		map = map->next;
	}
	return (0);
}

int	ft_check_errors(t_game *game, t_map *map)
{
	int	error;

	error = 0;
	if (ft_wall_rodated(map) || ft_map_rectangle(map) || ft_check_numbers(map)
		|| ft_check_flood_fill(map))
	{
		ft_putstr_fd("Error\n", 2);
		error = 1;
	}
	if (ft_check_flood_fill(map))
		ft_putstr_fd("El mapa no tiene un camino correcto\n", 2);
	if (ft_check_numbers(map))
		ft_putstr_fd("El mapa tiene carácteres irreconocibles\n", 2);
	if (ft_wall_rodated(map))
		ft_putstr_fd("El mapa debe estar rodeado de paredes\n", 2);
	if (ft_map_rectangle(map))
		ft_putstr_fd("El mapa no es rectangular\n", 2);
	if (ft_check_figures(game, map))
	{
		ft_send_msg(game);
		return (1);
	}
	return (error);
}
