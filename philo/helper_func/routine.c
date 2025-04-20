#include "../philo.h"

void    take_forks(t_philo *philo)
{
    pthread_mutex_lock(philo->left_fork);
    printf("%d %d has a take fork\n", get_time() , philo->id);
    pthread_mutex_lock(philo->right_fork);
    printf("%d %d has a take fork\n", get_time() , philo->id);
}

void    etaing(t_philo  *philo)
{
    printf("%d %d  is eating\n", get_time() , philo->id);
    usleep(philo->data->t_to_eat * 1000);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}
void    sleeping(t_philo *philo)
{
    printf("%d %d   is sleeping\n", get_time() , philo->id);
    usleep(philo->data->t_to_sleep * 1000);
}

void    thinking(t_philo *philo)
{
    int thinking_time;

    thinking_time = (philo->data->t_to_die - philo->data->t_to_eat - philo->data->t_to_sleep);
    if (thinking_time < 0)
    thinking_time = 0;

    printf("%d %d   is thinking\n", get_time(), philo->id);
    usleep(thinking_time * 1000);
}

void    died(t_philo *philo)
{
    
}
