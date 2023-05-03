/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:12:43 by pbengoec          #+#    #+#             */
/*   Updated: 2023/03/03 12:18:19 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_textures(t_textures textures)
{
	mlx_delete_texture(textures.exit);
	mlx_delete_texture(textures.wall);
	mlx_delete_texture(textures.position);
	mlx_delete_texture(textures.collec);
	mlx_delete_texture(textures.tower);
	mlx_delete_texture(textures.black);
	mlx_delete_texture(textures.white);
}

static void	ft_free_images(t_images images, mlx_t	*mlx)
{
	mlx_delete_image(mlx, images.exit);
	mlx_delete_image(mlx, images.wall);
	mlx_delete_image(mlx, images.position);
	mlx_delete_image(mlx, images.collec);
	mlx_delete_image(mlx, images.tower);
	mlx_delete_image(mlx, images.black);
	mlx_delete_image(mlx, images.white);
}

void	ft_free_game(t_game *game)
{
	ft_free_textures(game[0].textures);
	ft_free_images(game[0].images, game[0].mlx);
	ft_free_list(game[0].map);
}

void	ft_finish(t_game *game)
{
	game[0].finished = 1;
	ft_free_game(game);
	mlx_close_window(game[0].mlx);
}
