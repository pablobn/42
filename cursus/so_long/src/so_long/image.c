/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:03:25 by pbengoec          #+#    #+#             */
/*   Updated: 2023/03/03 11:51:40 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_img_bakground(char c, int x, int y, t_game *game)
{
	if (game[0].is_black)
		game[0].is_black = 0;
	else
		game[0].is_black = 1;
	if (c == '1')
	{
		mlx_image_to_window(game[0].mlx, game[0].images.wall, x, y);
		mlx_image_to_window(game[0].mlx, game[0].images.tower, x, y);
	}
	else
	{
		if (game[0].is_black)
			mlx_image_to_window(game[0].mlx, game[0].images.black, x, y);
		else
			mlx_image_to_window(game[0].mlx, game[0].images.white, x, y);
	}
}

static void	ft_set_img(char c, int x, int y, t_game *game)
{
	if (c == 'E')
		mlx_image_to_window(game[0].mlx, game[0].images.exit, x, y);
	else if (c == 'C')
	{
		mlx_image_to_window(game[0].mlx, game[0].images.collec, x, y);
		game[0].total_collec += 1;
	}
}

void	ft_create_img(t_game *game)
{
	char		*str;
	t_map		*map;
	int			x;
	int			y;

	y = 0;
	map = game[0].map;
	while (map)
	{
		str = map->line;
		x = 0;
		while (*str)
		{
			if (*str != '\n')
			{
				ft_set_img(*str, x, y, game);
				x += 64;
			}
			str++;
		}
		y += 64;
		map = map->next;
	}
	ft_create_pos(game);
}

void	ft_init_images(t_game *game)
{
	game[0].textures.wall = mlx_load_png("./images/wall.png");
	game[0].textures.tower = mlx_load_png("./images/tower.png");
	game[0].textures.position = mlx_load_png("./images/position.png");
	game[0].textures.white = mlx_load_png("./images/white.png");
	game[0].textures.black = mlx_load_png("./images/black.png");
	game[0].textures.exit = mlx_load_png("./images/exit.png");
	game[0].textures.collec = mlx_load_png("./images/collec.png");
	game[0].images.wall = \
	mlx_texture_to_image(game[0].mlx, game[0].textures.wall);
	game[0].images.tower = \
	mlx_texture_to_image(game[0].mlx, game[0].textures.tower);
	game[0].images.position = \
	mlx_texture_to_image(game[0].mlx, game[0].textures.position);
	game[0].images.white = \
	mlx_texture_to_image(game[0].mlx, game[0].textures.white);
	game[0].images.black = \
	mlx_texture_to_image(game[0].mlx, game[0].textures.black);
	game[0].images.exit = \
	mlx_texture_to_image(game[0].mlx, game[0].textures.exit);
	game[0].images.collec = \
	mlx_texture_to_image(game[0].mlx, game[0].textures.collec);
}
