/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:40:33 by pbengoec          #+#    #+#             */
/*   Updated: 2023/02/17 18:27:27 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void	*param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		movements(game[0], 1);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		movements(game[0], 2);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		movements(game[0], 3);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		movements(game[0], 4);
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
