/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:27:51 by pbengoec          #+#    #+#             */
/*   Updated: 2023/03/03 12:18:41 by pbengoec         ###   ########.fr       */
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
		ft_add_last(&map, line);
		line = get_next_line(fd);
	}
	return (map);
}

static t_game	*ft_init_game(t_game *game, int fd)
{
	game->map_height = 0;
	game->map_width = 0;
	game->moves = 0;
	game->c = 0;
	game->p = 0;
	game->finished = 0;
	game->e = 0;
	game->mlx = NULL;
	game->is_black = 1;
	game->map = ft_get_map(fd);
	ft_init_map(game, game->map);
	game->mlx = mlx_init(game->map_width, game->map_height, "MLX42", true);
	if (!game->mlx)
		game->mlx = NULL;
	ft_init_images(game);
	return (game);
}

int	ft_start(char *str)
{
	int		fd;
	t_game	*game;

	fd = open(str, O_RDONLY);
	game = malloc(sizeof(t_game));
	if (fd < 0)
	{
		ft_putstr_fd("Error\nNo se encuentra el archivo\n", 2);
		return (free(game), close(fd), 1);
	}
	game = ft_init_game(game, fd);
	if (game->mlx == NULL)
		return (free(game), close(fd), 1);
	if (ft_game(game[0]))
		return (free(game), close(fd), 1);
	close(fd);
	free(game);
	return (0);
}
