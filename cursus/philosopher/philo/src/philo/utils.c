/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:46:30 by pbengoec          #+#    #+#             */
/*   Updated: 2023/10/07 19:53:20 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time(long long time)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) != 0)
	{
		perror("Error al obtener la hora actual");
		return (0);
	}
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000 - time);
}

void	*ft_print(t_philo *philo, char *str, char *color)
{
	pthread_mutex_lock(&philo->info->locks[FINISH]);
	if (philo->info->finish)
	{
		pthread_mutex_unlock(&philo->info->locks[FINISH]);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->info->locks[FINISH]);
	printf("%s%lld %d %s%s\n", color, \
	ft_get_time(philo->info->time), philo->id, str, NC);
	return (NULL);
}

void	ft_refresh_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->locks[MEAL]);
		philo->last_eat = ft_get_time(philo->info->time);
	pthread_mutex_unlock(&philo->info->locks[MEAL]);
}

void	ft_custom_usleep(long long time, t_philo *philo)
{
	time = ft_get_time(philo->info->time) + time;
	while (ft_get_time(philo->info->time) < time)
	{
	}
}
