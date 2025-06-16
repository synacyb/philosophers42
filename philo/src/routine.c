/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:08:43 by ayadouay          #+#    #+#             */
/*   Updated: 2025/06/16 15:21:19 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	if (philo->data->n_philo < 2)
	{
		ft_log(philo, STATE_TAKE_FORK);
		ft_usleep(philo->data->t_to_die, philo->data);
		return (0);
	}
	else if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_log(philo, STATE_TAKE_FORK);
		pthread_mutex_lock(philo->right_fork);
		ft_log(philo, STATE_TAKE_FORK);
	}
	else
	{
		usleep(1000);
		pthread_mutex_lock(philo->right_fork);
		ft_log(philo, STATE_TAKE_FORK);
		pthread_mutex_lock(philo->left_fork);
		ft_log(philo, STATE_TAKE_FORK);
	}
	return (1);
}

void    etaing(t_philo  *philo)
{
	ft_log(philo, STATE_EATING);
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	ft_usleep(philo->data->t_to_eat, philo->data); 
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void    sleeping(t_philo *philo)
{
	ft_log(philo, STATE_SLEEPING);
	ft_usleep(philo->data->t_to_sleep, philo->data);
}

void    thinking(t_philo *philo)
{
	ft_log(philo, STATE_THINKING);
}
