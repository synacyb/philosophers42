#include "philo.h"

int	take_forks(t_philo *philo)
{
	if (philo->data->n_philo < 2)
	{
		ft_log(philo, STATE_TAKE_FORK);
		ft_usleep(philo->data->t_to_die);
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
	ft_usleep(philo->data->t_to_eat); // 1ms  1.3ms    
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void    sleeping(t_philo *philo)
{
	ft_log(philo, STATE_SLEEPING);
	ft_usleep(philo->data->t_to_sleep);
}

void    thinking(t_philo *philo)
{
	int thinking_time;

	thinking_time = (philo->data->t_to_die
		- (get_time() - philo->last_meal)
		- philo->data->t_to_eat) / 2;
	if (thinking_time <= 0)
		thinking_time = 0;
	else if (thinking_time > 200)
		thinking_time = 200;
	ft_log(philo, STATE_THINKING);
	ft_usleep(thinking_time);
}

