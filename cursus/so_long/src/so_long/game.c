/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:40:33 by pbengoec          #+#    #+#             */
/*   Updated: 2023/02/23 20:28:12 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void	*param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		movements(game, 1);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		movements(game, 2);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		movements(game, 3);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		movements(game, 4);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_finish(game);
}

int	ft_game(t_game game)
{
	if (ft_check_errors(&game, game.map))
	{
		ft_free_game(&game);
		return (1);
	}
	create_map(&game, game.map);
	create_img(&game);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (0);
}
