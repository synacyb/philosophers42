#include "philo.h"


t_philo *init_philos(t_data *data)
{
    int i;
    t_philo *philos;

    philos->data->forks = malloc(philos->data->n_philo * sizeof(pthread_mutex_t));
    philos = malloc(sizeof(t_philo) * data->n_philo);
    if (!philos)
        return (NULL);
    philos->data->start_time = get_time();

    i = 0;
    while (i < data->n_philo)
    {
        philos[i].id = i + 1;
        philos[i].meals_eaten = 0;
        philos[i].last_meal = get_time();
        philos[i].data = data;
        pthread_mutex_init(philos[i].data->forks, NULL);
        philos[i].left_fork = &data->forks[i];
        philos[i].right_fork = &data->forks[(i + 1) % data->n_philo];

        i++;
    }
    return philos;
}
