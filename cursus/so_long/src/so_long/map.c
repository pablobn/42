/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:05:04 by pbengoec          #+#    #+#             */
/*   Updated: 2023/02/23 19:47:52 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_map(t_map *map, int size)
{
	int	i;

	i = 0;
	while (map)
	{
		i += size;
		map = map->next;
	}
	return (i);
}

int	len_map_line(t_map *map, int size)
{
	int		i;
	char	*line;

	i = 0;
	line = map->line;
	while (*line)
	{
		if (*line != '\n')
			i += size;
		line++;
	}
	return (i);
}

static void	check_if_black(t_game *game)
{
	if (game[0].first_color == game[0].is_black)
	{
		if (game[0].is_black == 1)
			game[0].is_black = 0;
		else
			game[0].is_black = 1;
	}
}

void	create_map(t_game *game, t_map *map)
{
	char		*str;
	int			x;
	int			y;

	y = 0;
	while (map)
	{
		str = map->line;
		x = 0;
		game[0].first_color = game[0].is_black;
		while (*str)
		{
			if (*str != '\n')
			{
				set_img_bakground(*str, x, y, game);
				x += 64;
			}
			str++;
		}
		check_if_black(game);
		y += 64;
		map = map->next;
	}
}

void	init_map(t_game	*game, t_map *map)
{
	game[0].map_height = len_map(map, 64);
	game[0].map_width = len_map_line(map, 64);
}
