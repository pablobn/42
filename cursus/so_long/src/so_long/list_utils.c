/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:46:38 by pbengoec          #+#    #+#             */
/*   Updated: 2023/03/03 11:48:53 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_add_last(t_map **map, char *dato)
{
	t_map	*new;
	t_map	*last_node;

	new = malloc(sizeof(t_map));
	new->line = dato;
	new->next = NULL;
	if (*map == NULL)
		*map = new;
	else
	{
		last_node = *map;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new;
	}
}

void	ft_free_list(t_map *map)
{
	t_map	*tmp;

	while (map)
	{
		tmp = map;
		map = map->next;
		free(tmp->line);
		free(tmp);
	}
}
