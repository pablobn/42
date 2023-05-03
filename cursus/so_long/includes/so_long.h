/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:15:05 by pbengoec          #+#    #+#             */
/*   Updated: 2023/03/03 11:49:17 by pbengoec         ###   ########.fr       */
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
	t_map		*map;
	int			p;
	int			e;
	int			c;
	int			map_width;
	int			map_height;
	int			is_black;
	int			moves;
	int			first_color;
	int			total_collec;
	int			finished;
}t_game;

typedef struct point
{
	int		y;
	int		x;
	char	target;
}t_point;

void	ft_add_last(t_map **map, char *dato);
void	ft_create_img(t_game *game);
void	ft_init_images(t_game *game);
void	ft_init_map(t_game	*game, t_map *map);
void	ft_free_list(t_map *map);
int		ft_start(char *str);
int		ft_game(t_game game);
char	*get_next_line(int fd);
void	ft_create_map(t_game *game, t_map *map);
void	ft_set_img_bakground(char c, int x, int y, t_game *game);
void	ft_movements(t_game *game, int dir);
void	ft_finish(t_game *game);
int		ft_check_errors(t_game *game, t_map *map);
int		ft_len_map_line(t_map *map, int size);
int		ft_len_map(t_map *map, int size);
void	ft_free_game(t_game *game);
int		ft_check_flood_fill(t_map *map);
void	ft_send_msg(t_game *game);
void	ft_create_pos(t_game *game);

#endif
