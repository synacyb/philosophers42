/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:45:59 by ayadouay          #+#    #+#             */
/*   Updated: 2025/05/07 16:27:51 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	ft_check_meal(t_data *data)
// {
	
// }

int	ft_check_died(t_data *data)
{
	int	i;
	int stop;
	time_t current_time;

	i = 0;
	stop = 0;
	current_time = get_time();
	pthread_mutex_lock(&data->meal_mutex);
	while (i < data->n_philo)
	{
		if (current_time - data->philos[i].last_meal > data->t_to_die)
		{
			stop = 1;
			pthread_mutex_unlock(&data->meal_mutex);
			ft_log(&data->philos[i], STATE_DEAD);
			pthread_mutex_lock(&data->stop_mutex);
			data->stop = 1;
			pthread_mutex_unlock(&data->stop_mutex);
			return (stop);
		}
		i++;
	}
	pthread_mutex_unlock(&data->meal_mutex);
	return (stop);
}

void	*ft_watcher(void *arg)
{
	t_data *data;

	data = (t_data *)arg;

	while (1)
	{
		usleep(500);
		// TODO: Iterate over each philo and check the last meal time and died time
		if (ft_check_died(data))
			break;
		
		
		// TODO: Check the stop flag and break if ON
		// TODO: Check the meal counter for each philo, if all of them has finishing eating then stop simulation
	}
	return (NULL);
}
