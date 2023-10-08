/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:11:20 by pbengoec          #+#    #+#             */
/*   Updated: 2023/10/05 16:11:21 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_mutex(pthread_mutex_t *mutex, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&mutex[i]);
		i++;
	}
}

void	ft_free_all(t_info *info)
{
	ft_free_mutex(info->forks, info->max);
	free(info->forks);
	ft_free_mutex(info->locks, TOTAL);
	free(info->locks);
	free(info->philo);
}
