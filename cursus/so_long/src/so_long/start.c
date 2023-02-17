/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:27:51 by pbengoec          #+#    #+#             */
/*   Updated: 2023/02/14 16:10:08 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	*ft_get_map(int fd)
{
	t_map	*map;
	char	*line;

	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		add_last(&map, line);
		line = get_next_line(fd);
	}
	return (map);
}

void	ft_start(char *str)
{
	int		fd;
	t_map	*map;

	fd = open(str, O_RDONLY);
	printf("%s\n", str);
	if (fd < 0)
		return ;
	map = ft_get_map(fd);
	game(&map);
	free_list(map);
	close(fd);
}
