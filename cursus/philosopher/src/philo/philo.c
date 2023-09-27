/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:03:35 by pbengoec          #+#    #+#             */
/*   Updated: 2023/09/27 18:14:15 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) != 0)
	{
		perror("Error al obtener la hora actual");
		return (0);
	}
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_philo_eats(t_info *info, int id)
{
	pthread_mutex_lock(&info->locks[id - 1]);
	printf("%s%lld Philosopher %d has taken a fork%s\n", RED, ft_get_time(), id, NC);
	if (id == 1)
		pthread_mutex_lock(&info->locks[info->max - 1]);
	else
		pthread_mutex_lock(&info->locks[id - 2]);
	printf("%lld Philosopher %d has taken a fork\n", ft_get_time(), id);
	printf("%s%lld Philosopher %d is eating%s\n", BYELLOW, ft_get_time(), id, NC);
	usleep(info->eat * 1000);
	pthread_mutex_unlock(&info->locks[id - 1]);
	if (id == 1)
		pthread_mutex_unlock(&info->locks[info->max - 1]);
	else
		pthread_mutex_unlock(&info->locks[id - 2]);
	printf("%s%lld Philosopher %d finished%s\n", YELLOW, ft_get_time(), id, NC);
}

void	*ft_philo(void *data)
{
	t_info			*info;
	int				id;

	info = (t_info *) data;
	id = info->id;
	ft_philo_eats(info, id);
	return (NULL);
}

void	ft_create_philo(t_info *info)
{
	int				i;
	pthread_t		*threads;

	threads = (pthread_t *) malloc(sizeof(pthread_t) * info->max);
	if (!threads)
		return ;
	i = 0;
	while (i < info->max)
	{
		info[i].id = i + 1;
		pthread_create(&threads[i], NULL, ft_philo, &info[i]);
		i++;
	}
	i = 0;
	while (i < info->max)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	ft_free_all(info);
}

int	ft_init(char **av)
{
	t_info			*info;
	int				i;
	int				num;
	pthread_mutex_t	*mutex;

	num = ft_atoi(av[1]);
	info = malloc(sizeof(t_info) * num);
	mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * num);
	if (!mutex)
		return (1);
	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	i = 0;
	while (i < num)
	{
		info[i].eat = ft_atoi(av[3]);
		info[i].die = ft_atoi(av[2]);
		info[i].max = num;
		info[i].locks = mutex;
		i++;
	}
	ft_create_philo(info);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	return (ft_init(av));
}
