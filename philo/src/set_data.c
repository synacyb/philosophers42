/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:08:51 by ayadouay          #+#    #+#             */
/*   Updated: 2025/06/19 13:34:27 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
		pthread_mutex_init(&data->forks[i++], NULL);
}

int	set_data(t_data *data, char **args, int ac)
{
	data->n_philo = ft_atoi(args[1]);
	data->t_to_die = ft_atoi(args[2]);
	data->t_to_eat = ft_atoi(args[3]);
	data->t_to_sleep = ft_atoi(args[4]);
	if (ac == 6)
		data->n_t_must_eat = ft_atoi(args[5]);
	else
		data->n_t_must_eat = -1;
	data->forks = malloc(data->n_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (EXIT_FAILURE);
	init_forks(data);
	data->philos = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philos)
		return (EXIT_FAILURE);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->meal_mutex, NULL);
	pthread_mutex_init(&data->stop_mutex, NULL);
	data->stop = 0;
	return (EXIT_SUCCESS);
}

int	ft_clean(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->stop_mutex);
	free(data->forks);
	free(data->philos);
	return (EXIT_SUCCESS);
}
