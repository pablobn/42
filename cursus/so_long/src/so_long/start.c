/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:27:51 by pbengoec          #+#    #+#             */
/*   Updated: 2023/03/01 18:05:51 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	*ft_get_map(int fd)
{
	t_map	*map;
	char	*line;

	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		add_last(&map, line);
		line = get_next_line(fd);
	}
	return (map);
}

t_game	init_game(int fd)
{
	t_game	game;

	game.map_height = 0;
	game.map_width = 0;
	game.moves = 0;
	game.c = 0;
	game.p = 0;
	game.finished = 0;
	game.e = 0;
	game.mlx = NULL;
	game.is_black = 1;
	game.map = ft_get_map(fd);
	init_map(&game, game.map);
	game.mlx = mlx_init(game.map_width, game.map_height, "MLX42", true);
	if (!game.mlx)
		game.mlx = NULL;
	init_images(&game);
	return (game);
}

int	ft_start(char *str)
{
	int		fd;
	t_game	game;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nNo se encuentra el archivo\n", 2);
		return (close(fd), 1);
	}
	game = init_game(fd);
	if (game.mlx == NULL)
		return (close(fd), 1);
	if (ft_game(game))
		return (close(fd), 1);
	close(fd);
	return (0);
}
