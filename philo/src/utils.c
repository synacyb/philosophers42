/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:06:03 by ayadouay          #+#    #+#             */
/*   Updated: 2025/05/07 16:18:36 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_check_stop(t_data *data)
{
    int stop;
    
    stop = 0;
    pthread_mutex_lock(&data->stop_mutex);
    if (data->stop)
    {
        stop = 1;
    }
    pthread_mutex_unlock(&data->stop_mutex);
    return (stop);
    
}

void	ft_log(t_philo *philo, int status)
{
	if (ft_check_stop(philo->data))
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	if (status == STATE_TAKE_FORK)
		printf("%ld %d has a take fork\n", get_time() - philo->data->start_time, philo->id);
	else if (status == STATE_EATING)
		printf("%ld %d  is eating\n", get_time() - philo->data->start_time, philo->id);
	else if (status == STATE_SLEEPING)
		printf("%ld %d   is sleeping\n", get_time() - philo->data->start_time, philo->id);
	else if (status == STATE_THINKING)
		printf("%ld %d   is thinking\n", get_time() - philo->data->start_time, philo->id);
	else if (status == STATE_DEAD)
		printf("%ld %d   is died\n", get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);

}
