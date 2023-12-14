/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:01:51 by pbengoec          #+#    #+#             */
/*   Updated: 2023/11/29 18:02:08 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>
# include <pthread.h>

//COLORES
# define NC			"\e[0m"
# define YELLOW		"\e[33m"
# define BYELLOW	"\e[1;33m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define BLUE		"\e[34m"
# define CYAN		"\e[36m"

//MUTEX
# define TOTAL		5
# define START	 	0
# define STATUS	 	1
# define MEAL		2
# define FINISH		3
# define EATING     4

struct	s_info;

typedef struct s_philo
{
	int				id;
	int				status;
	long long		last_eat;
	long long		eat;
	long long		sleep;
	int				time_eats;
	int				fork_left;
	int				fork_right;
	struct s_info	*info;
}t_philo;

typedef struct s_info
{
	int				die;
	long long		time;
	int				finish;
	int				eat;
	int				sleep;
	int				max_eats;
	int				max;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*locks;
	int				error;
	t_philo			*philo;
}	t_info;

void		*ft_thread_philo(void *data);
void		*ft_thread_supervisor(void *data);
long long	ft_get_time(long long time);
void		*ft_print(t_philo *philo, char *str, char *color);
void		ft_refresh_eat(t_philo *philo);
void		ft_free_all(t_info *info);
void		*ft_thread_supervisor(void *data);
void		ft_prepare_thread(t_info *info);
void		ft_philo_one(t_philo *philo);
void		ft_philo_sleeps(t_philo *philo);
void		ft_philo_eats(t_philo	*philo);
void		ft_philo_thinks(t_philo *philo);
int			ft_atoi(const char *str);
void		ft_custom_usleep(long long time, t_philo *philo);
#endif