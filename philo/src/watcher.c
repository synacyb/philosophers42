/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:45:59 by ayadouay          #+#    #+#             */
/*   Updated: 2025/06/21 15:34:37 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_meal(t_data *data)
{
	int	i;
	int	finished;

	i = 0;
	finished = 0;
	pthread_mutex_lock(&data->meal_mutex);
	while (i < data->n_philo)
	{
		if (data->philos[i].meals_eaten >= data->n_t_must_eat)
			finished++;
		i++;
	}
	pthread_mutex_unlock(&data->meal_mutex);
	if (finished == data->n_philo)
		return (1);
	return (0);
}

int	ft_check_died(t_data *data)
{
	int		i;
	time_t	current_time;

	current_time = 0;
	i = 0;
	while (i < data->n_philo)
	{
		current_time = get_time();
		pthread_mutex_lock(&data->meal_mutex);
		if (current_time - data->philos[i].last_meal > data->t_to_die)
		{
			pthread_mutex_unlock(&data->meal_mutex);
			ft_log(&data->philos[i], STATE_DEAD);
			pthread_mutex_lock(&data->stop_mutex);
			data->stop = 1;
			pthread_mutex_unlock(&data->stop_mutex);
			return (1);
		}
		pthread_mutex_unlock(&data->meal_mutex);
		i++;
	}
	return (0);
}

void	*ft_watcher(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	if (data->n_t_must_eat == 0)
		return (NULL);
	while (1)
	{
		if (data->n_t_must_eat != -1)
		{
			if (ft_check_meal(data))
			{
				pthread_mutex_lock(&data->stop_mutex);
				data->stop = 1;
				pthread_mutex_unlock(&data->stop_mutex);
				break ;
			}
		}
		if (ft_check_died(data))
			break ;
		usleep(1000);
	}
	return (NULL);
}
