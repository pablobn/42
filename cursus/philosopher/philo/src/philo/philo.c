/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:03:35 by pbengoec          #+#    #+#             */
/*   Updated: 2023/10/07 19:50:45 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*ft_init_mutex(int num)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * num);
	if (!mutex)
		return (NULL);
	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	return (mutex);
}

t_philo	*ft_create_philo(t_info *info)
{
	int				i;
	t_philo			*philo;

	philo = (t_philo *) malloc(info->max * sizeof(t_philo));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < info->max)
	{
		philo[i].id = i + 1;
		philo[i].status = 0;
		philo[i].sleep = info->sleep;
		philo[i].eat = info->eat;
		philo[i].last_eat = 0;
		philo[i].time_eats = 0;
		philo[i].fork_right = i;
		philo[i].info = info;
		if (i == info->max - 1)
			philo[i].fork_left = 0;
		else
			philo[i].fork_left = i + 1;
		i++;
	}
	return (philo);
}

t_info	ft_create_info(char **av)
{
	t_info	info;

	info.eat = ft_atoi(av[3]);
	info.error = 0;
	info.sleep = ft_atoi(av[4]);
	info.die = ft_atoi(av[2]);
	info.max = ft_atoi(av[1]);
	info.max_eats = -1;
	if (info.max <= 0 || info.sleep <= 0 || info.eat <= 0 || info.die <= 0)
	{
		info.error = 1;
		return (info);
	}
	if (av[5])
	{
		info.max_eats = ft_atoi(av[5]);
		if (info.max_eats <= 0)
		{
			info.error = 1;
			return (info);
		}
	}
	info.finish = 0;
	return (info);
}

int	ft_init(char **av)
{
	t_info	info;

	info = ft_create_info(av);
	if (info.error)
		return (1);
	info.philo = ft_create_philo(&info);
	info.locks = ft_init_mutex(TOTAL);
	info.forks = ft_init_mutex(info.max);
	if (!info.forks || !info.philo)
		return (ft_free_all(&info), 1);
	ft_prepare_thread(&info);
	ft_free_all(&info);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	return (ft_init(av));
}
