/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:08:56 by pbengoec          #+#    #+#             */
/*   Updated: 2023/10/07 19:53:32 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_eats(t_philo	*philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->fork_right]);
	ft_print(philo, "has taken a fork", CYAN);
	pthread_mutex_lock(&philo->info->forks[philo->fork_left]);
	ft_print(philo, "has taken a fork", BLUE);
	ft_print(philo, "is eating", BYELLOW);
	ft_refresh_eat(philo);
	ft_custom_usleep(philo->eat, philo);
	pthread_mutex_lock(&philo->info->locks[EATING]);
	philo->time_eats++;
	pthread_mutex_unlock(&philo->info->locks[EATING]);
	pthread_mutex_unlock(&philo->info->forks[philo->fork_right]);
	pthread_mutex_unlock(&philo->info->forks[philo->fork_left]);
}

void	ft_philo_sleeps(t_philo *philo)
{
	ft_print(philo, "is sleeping", YELLOW);
	ft_custom_usleep(philo->sleep, philo);
}

void	ft_philo_thinks(t_philo *philo)
{
	ft_print(philo, "is thinking", GREEN);
}

void	ft_philo_one(t_philo *philo)
{
	ft_print(philo, "has taken a fork", CYAN);
	ft_custom_usleep(philo->info->die, philo);
}
