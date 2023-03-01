/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:25:43 by pbengoec          #+#    #+#             */
/*   Updated: 2023/03/01 12:34:21 by pbengoec         ###   ########.fr       */
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

static void	forbidden_move(t_game game, int x, int y)
{
	int	i;
	int	pasar;

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

static void	collection_move(t_game game, int x, int y)
{
	int	i;
	int	remove;

	remove = 0;
	i = 0;
	while (i <= game.total_collec && remove == 0)
	{
		if (game.images.collec->instances[i].x == x
			&& game.images.collec->instances[i].y == y)
			remove = 1;
		i++;
	}
	if (remove)
	{
		i--;
		game.images.collec->instances[i].enabled = 0;
	}
}

static void	end_game(t_game *game, int x, int y)
{
	int	i;
	int	collec;

	collec = 1;
	i = 0;
	if (game[0].images.exit->instances[0].x == x
		&& game[0].images.exit->instances[0].y == y)
	{
		while (i < game[0].total_collec)
		{
			if (game[0].images.collec->instances[i].enabled)
				collec = 0;
			i++;
		}
		if (collec)
			ft_finish(game);
	}
}

void	movements(t_game *game, int dir)
{
	int		x;
	int		y;
	char	*num;

	x = move_position(dir, game[0].images.position->instances[0].x, 1);
	y = move_position(dir, game[0].images.position->instances[0].y, 2);
	forbidden_move(game[0], x, y);
	collection_move(game[0], x, y);
	game[0].moves += 1;
	num = ft_itoa(game[0].moves);
	ft_putstr_fd(num, 1);
	ft_putstr_fd("\n", 1);
	free(num);
	end_game(game, x, y);
}
