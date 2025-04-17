#include "philo.h"


// void    eating(t_philo  *data)
// {

// }

void    *life_cycel(void *arg)
{
    t_philo *philo;
    philo = (t_philo *)arg;

    printf("philo id = %d\n", philo->id);
    return (NULL);
}

void    create_threads(t_data *data)
{
    int i = 0;

    while (i < data->n_philo)
    {
        pthread_create(&data->philos[i].thread, NULL, &life_cycel, &data->philos[i]);
        i++;
    }
    

    i = 0;

    while (i < data->n_philo)
    {
        pthread_join(data->philos[i].thread, NULL);
        i++;
    }
}
