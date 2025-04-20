#include "philo.h"

void    init_philos(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philo)
    {
        data->philos[i].id = i + 1;
        data->philos[i].meals_eaten = 0;
        data->philos[i].last_meal = get_time();
        data->philos[i].data = data;
        
        if(data->n_philo % 2 == 0)
        {
            data->philos[i].right_fork = &data->forks[i];
            data->philos[i].left_fork = &data->forks[(i + 1) % data->n_philo];
        }
        else
        {
            data->philos[i].left_fork = &data->forks[(i + 1) % data->n_philo];
            data->philos[i].right_fork = &data->forks[i];
        }
        i++;
    }
}
