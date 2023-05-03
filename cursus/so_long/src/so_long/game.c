/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:40:33 by pbengoec          #+#    #+#             */
/*   Updated: 2023/03/03 11:44:10 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_my_keyhook(mlx_key_data_t keydata, void	*param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_movements(game, 1);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_movements(game, 2);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_movements(game, 3);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_movements(game, 4);
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
	ft_create_map(&game, game.map);
	ft_create_img(&game);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx_key_hook(game.mlx, &ft_my_keyhook, &game);
	mlx_loop(game.mlx);
	if (game.finished == 0)
		ft_finish(&game);
	return (0);
}
