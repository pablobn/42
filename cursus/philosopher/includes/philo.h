/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:01:51 by pbengoec          #+#    #+#             */
/*   Updated: 2023/09/27 17:36:59 by pbengoec         ###   ########.fr       */
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
# include "../library/libft/libft.h"

#define NC	"\e[0m"
#define YELLOW	"\e[33m"
#define BYELLOW	"\e[1;33m"
#define RED	"\e[31m"
#define GREEN	"\e[32m"

typedef struct s_info
{
	pthread_mutex_t	*locks;
	int				id;		
	int				die;
	int				eat;
	int				sleep;
	int				time_eat;
	int				max;
}	t_info;

void	ft_create_philo(t_info *info);
void	ft_free_all(t_info *info);

#endif