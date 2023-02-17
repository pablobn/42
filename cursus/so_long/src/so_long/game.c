/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:40:33 by pbengoec          #+#    #+#             */
/*   Updated: 2023/02/15 16:41:00 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_position(int dir, int x, int num)
{
	if (num == 1)
	{
		if (dir == 1)
			x -= 64;
		else if (dir == 3)
			x += 64;
	}
	else
	{
		if (dir == 2)
			x += 64;
		else if (dir == 4)
			x -= 64;
	}
	return (x);
}

static void	forbidden_move(t_game game, int dir)
{
	int	i;
	int	x;
	int	y;
	int	pasar;

	x = move_position(dir, game.images.position->instances[0].x, 1);
	y = move_position(dir, game.images.position->instances[0].y, 2);
	pasar = 1;

	i = 0;
	while (game.images.wall->instances[i].enabled && pasar)
	{
		if (game.images.wall->instances[i].x == x
			&& game.images.wall->instances[i].y == y)
			pasar = 0;
		i++;
	}
	if (pasar)
	{
		game.images.position->instances[0].x = x;
		game.images.position->instances[0].y = y;
	}
}

static void	collection_move(t_game game, int dir)
{
	int	i;
	int	x;
	int	y;
	int	remove;

	x = move_position(dir, game.images.position->instances[0].x, 1);
	y = move_position(dir, game.images.position->instances[0].y, 2);
	remove = 0;

	i = 0;
	while (game.images.wall->instances[i].enabled && remove == 0)
	{
		if (game.images.wall->instances[i].x == x
			&& game.images.wall->instances[i].y == y)
			remove = 1;
		i++;
	}
	if (remove)
	{
		game.images.position->instances[0].x = x;
		game.images.position->instances[0].y = y;
	}
}

void	movements(t_game game, int dir)
{
	forbidden_move(game, dir);
	collection_move(game, dir);
}

void	my_keyhook(mlx_key_data_t keydata, void	*param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		movements(game[0] ,1);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		movements(game[0] ,2);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		movements(game[0] ,3);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		movements(game[0] ,4);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game[0].mlx);
}

t_game	init_game(t_map *map)
{
	t_game		game;

	game.map_height = 0;
	game.map_width = 0;
	game.mlx = NULL;
	game.is_black = 1;
	init_map(&game, map);
	game.mlx = mlx_init(game.map_width, game.map_height, "MLX42", true);
	if (!game.mlx)
		game.mlx = NULL;
	init_images(&game);
	return (game);
}

void	game(t_map **map)
{
	t_game		game;

	game = init_game(map[0]);
	if (game.mlx == NULL)
		return ;
	create_map(map[0], &game);
	create_img(map[0], &game);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return ;
}
