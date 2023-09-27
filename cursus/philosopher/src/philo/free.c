#include "philo.h"

void	ft_free_all(t_info *info)
{
	int i;

	i = 0;
	while (i < info->max)
	{
		pthread_mutex_destroy(&info->locks[i]);
		i++;
	}
}
