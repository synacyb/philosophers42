#include "philo.h"

void *life_cycel(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    // if (philo->data->n_philo == 1)
    // {
    //     printf("%d %d %s\n", 0, 1, "has taken a fork");
    //     if(usleep(philo->data->t_to_die * 1000) == -1)
    //         printf("usleep has filie !!");
    //     else
    //         printf("%d %d %s\n", philo->data->t_to_die, 1, "died");
    //     return NULL;
    // }
    if(philo->id % 2 == 0)
        ft_usleep(1);
    while (1)
    {
        if (ft_check_stop(philo->data))
            break ;
        if (take_forks(philo) == 0)
            break ;
        etaing(philo);
        sleeping(philo);
        thinking(philo);
    }

    return NULL;
}

void    create_threads(t_data *data)
{
    int i = 0;
    data->start_time = get_time();
    while (i < data->n_philo)
    {
        data->philos[i].last_meal = data->start_time;
        pthread_create(&data->philos[i].thread, NULL, &life_cycel, &data->philos[i]);
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
