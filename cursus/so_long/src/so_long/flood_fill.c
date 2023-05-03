/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:55:27 by pbengoec          #+#    #+#             */
/*   Updated: 2023/03/06 12:13:24 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_array(t_map *map, char **arr)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (map)
	{
		line = map->line;
		j = 0;
		while (*line && *line != '\n')
		{
			arr[i][j] = *line;
			j++;
			line++;
		}
		map = map->next;
		i++;
	}
}

static void	ft_free_array(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	ft_f_fill(char **tab, t_point size, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (tab[row][col] == 'F' || tab[row][col] == size.target)
		return ;
	tab[row][col] = 'F';
	ft_f_fill(tab, size, row -1, col);
	ft_f_fill(tab, size, row +1, col);
	ft_f_fill(tab, size, row, col - 1);
	ft_f_fill(tab, size, row, col + 1);
}

static int	ft_check_map(char **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != '1' && tab[i][j] != 'F' && tab[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_flood_fill(t_map *map)
{
	char	**arr;
	t_point	size;
	int		i;

	size.y = ft_len_map(map, 1);
	size.x = ft_len_map_line(map, 1);
	size.target = '1';
	arr = malloc(sizeof(char **) * size.y);
	if (!arr)
		return (1);
	i = 0;
	while (i < size.y)
	{
		arr[i] = malloc(sizeof(char *) * size.x);
		if (!arr[i])
			return (1);
		arr[i][size.x] = '\0';
		i++;
	}
	ft_init_array(map, arr);
	ft_f_fill(arr, size, 1, 1);
	if (ft_check_map(arr, size.y))
		return (ft_free_array(arr, size.y), 1);
	return (ft_free_array(arr, size.y), 0);
}
