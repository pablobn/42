/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:08:21 by pbengoec          #+#    #+#             */
/*   Updated: 2023/10/07 19:27:42 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_starting_thread(t_info *info)
{
	int	check;
	int	i;

	pthread_mutex_lock(&info->locks[START]);
	check = 1;
	while (check)
	{
		i = 0;
		while (i < info->max)
		{
			pthread_mutex_lock(&info->locks[STATUS]);
			if (info->philo[i].status)
				check = 0;
			else
				check = 1;
			pthread_mutex_unlock(&info->locks[STATUS]);
			i++;
		}
	}
	info->time = ft_get_time(0);
	pthread_mutex_unlock(&info->locks[START]);
}

void	ft_check_dead(t_info *info, int i)
{
	pthread_mutex_lock(&info->locks[MEAL]);
	if (ft_get_time(info->time) - info->philo[i].last_eat > info->die)
	{
		ft_print(&info->philo[i], " is dead ", GREEN);
		pthread_mutex_lock(&info->locks[FINISH]);
		info->finish = 1;
		pthread_mutex_unlock(&info->locks[FINISH]);
	}
	pthread_mutex_unlock(&info->locks[MEAL]);
}

void	ft_change_dead(t_info *info, int check)
{		
	pthread_mutex_lock(&info->locks[FINISH]);
	if (check == 0)
		info->finish = 1;
	pthread_mutex_unlock(&info->locks[FINISH]);
}

void	ft_check_times(t_info *info, int i, int check)
{
	pthread_mutex_lock(&info->locks[EATING]);
	if (info->philo[i].time_eats >= info->max_eats)
		check = 0;
	else
		check = 1;
	pthread_mutex_unlock(&info->locks[EATING]);
}

void	*ft_thread_supervisor(void *data)
{
	t_info	*info;
	int		i;
	int		check;

	info = (t_info *) data;
	ft_starting_thread(info);
	check = 1;
	while (check && !info->finish)
	{
		i = 0;
		check = 1;
		while (i < info->max && !info->finish)
		{
			ft_check_dead(info, i);
			if (info->philo[i].time_eats != -1)
				ft_check_times(info, i, check);
			i++;
		}
		ft_change_dead(info, check);
	}
	return (NULL);
}
