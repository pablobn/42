/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:15:05 by pbengoec          #+#    #+#             */
/*   Updated: 2023/02/15 13:39:47 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include "../library/libft/libft.h"
# include "../library/MLX42/include/MLX42/MLX42.h"
# include <memory.h>
# include <fcntl.h>

# define WIDTH 1000
# define HEIGHT 500

typedef struct map
{
	char		*line;
	struct map	*next;
}t_map;

typedef struct textures
{
	mlx_texture_t	*exit;
	mlx_texture_t	*wall;
	mlx_texture_t	*position;
	mlx_texture_t	*collec;
	mlx_texture_t	*interior;
	mlx_texture_t	*tower;
	mlx_texture_t	*black;
	mlx_texture_t	*white;
}t_textures;

typedef struct images
{
	mlx_image_t	*exit;
	mlx_image_t	*wall;
	mlx_image_t	*position;
	mlx_image_t	*collec;
	mlx_image_t	*tower;
	mlx_image_t	*black;
	mlx_image_t	*white;
}t_images;

typedef struct game
{
	mlx_t		*mlx;
	t_images	images;
	t_textures	textures;
	int			map_width;
	int			map_height;
	int			is_black;
	int			first_color;
}t_game;

void	add_last(t_map **map, char *dato);
void	create_img(t_map *map, t_game *game);
void	init_images(t_game *game);
void	init_map(t_game	*game, t_map *map);
void	free_list(t_map *map);
void	show_map(t_map **map);
void	ft_start(char *str);
void	game(t_map **map);
char	*get_next_line(int fd);
void	create_map(t_map *map, t_game *game);
void	set_img_bakground(char c, int x, int y, t_game *game);
#endif
