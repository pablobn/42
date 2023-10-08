/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:31:06 by pbengoec          #+#    #+#             */
/*   Updated: 2023/10/05 17:11:18 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_routine(t_philo *philo)
{
	int	i;

	if (philo->info->max == 1)
		ft_philo_one(philo);
	if (philo->id % 2 == 0)
		usleep(10000);
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->info->locks[FINISH]);
		if (philo->info->finish)
		{
			pthread_mutex_unlock(&philo->info->locks[FINISH]);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->info->locks[FINISH]);
		ft_philo_eats(philo);
		ft_philo_sleeps(philo);
		ft_philo_thinks(philo);
		i++;
	}
	return (NULL);
}

void	*ft_thread_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	pthread_mutex_lock(&philo->info->locks[STATUS]);
	philo->status = 1;
	pthread_mutex_unlock(&philo->info->locks[STATUS]);
	pthread_mutex_lock(&philo->info->locks[START]);
	pthread_mutex_unlock(&philo->info->locks[START]);
	ft_philo_routine(philo);
	return (NULL);
}

void	ft_prepare_thread(t_info *info)
{
	int			i;
	pthread_t	supervisor;
	pthread_t	*philosophers;

	philosophers = (pthread_t *) malloc(sizeof(pthread_t) * info->max);
	if (!philosophers)
		return ;
	pthread_create(&supervisor, NULL, ft_thread_supervisor, info);
	i = 0;
	while (i < info->max)
	{
		pthread_create(&philosophers[i], NULL, \
		ft_thread_philo, &info->philo[i]);
		i++;
	}
	pthread_join(supervisor, NULL);
	i = 0;
	while (i < info->max)
	{
		pthread_join(philosophers[i], NULL);
		i++;
	}
	free(philosophers);
}
