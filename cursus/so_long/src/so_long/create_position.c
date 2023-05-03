/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:36:41 by pbengoec          #+#    #+#             */
/*   Updated: 2023/03/03 11:37:37 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_set_img_pos(char c, int x, int y, t_game *game)
{
	if (c == 'P')
		mlx_image_to_window(game[0].mlx, game[0].images.position, x, y);
}

void	ft_create_pos(t_game *game)
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
				ft_set_img_pos(*str, x, y, game);
				x += 64;
			}
			str++;
		}
		y += 64;
		map = map->next;
	}
}
