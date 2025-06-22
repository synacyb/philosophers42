/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:08:24 by ayadouay          #+#    #+#             */
/*   Updated: 2025/06/22 17:23:18 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_etaing(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meal_mutex);
	if (philo->data->n_t_must_eat == -1
		|| philo->meals_eaten < philo->data->n_t_must_eat)
	{
		pthread_mutex_unlock(&philo->data->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->meal_mutex);
	return (0);
}

void	*life_cycel(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->n_t_must_eat == 0)
		return (NULL);
	while (!ft_check_stop(philo->data) && check_etaing(philo) == 1)
	{
		if (ft_check_stop(philo->data))
			break ;
		if (take_forks(philo) == 0)
			break ;
		if (ft_check_stop(philo->data))
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			break ;
		}
		etaing(philo);
		if (ft_check_stop(philo->data))
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	create_threads(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->n_philo)
	{
		data->philos[i].last_meal = data->start_time;
		pthread_create(&data->philos[i].thread, NULL, &life_cycel,
			&data->philos[i]);
		i++;
	}
	pthread_create(&data->watcher, NULL, &ft_watcher, data);
	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	pthread_join(data->watcher, NULL);
}
