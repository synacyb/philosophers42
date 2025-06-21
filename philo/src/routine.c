/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:08:43 by ayadouay          #+#    #+#             */
/*   Updated: 2025/06/21 16:15:16 by ayadouay         ###   ########.fr       */
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
		usleep(2500);
		pthread_mutex_lock(philo->right_fork);
		ft_log(philo, STATE_TAKE_FORK);
		pthread_mutex_lock(philo->left_fork);
		ft_log(philo, STATE_TAKE_FORK);
	}
	return (1);
}

void	etaing(t_philo *philo)
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

void	sleeping(t_philo *philo)
{
	ft_log(philo, STATE_SLEEPING);
	ft_usleep(philo->data->t_to_sleep, philo->data);
}

void	thinking(t_philo *philo)
{
	time_t	smart_think;

	ft_log(philo, STATE_THINKING);
	if (philo->data->n_philo % 2 != 0)
	{
		pthread_mutex_lock(&philo->data->meal_mutex);
		smart_think = (philo->data->t_to_die - \
		(get_time() - philo->last_meal)) * 0.8;
		pthread_mutex_unlock(&philo->data->meal_mutex);
		if (smart_think < 0)
			smart_think = 0;
		usleep(smart_think * 1000);
	}
}
