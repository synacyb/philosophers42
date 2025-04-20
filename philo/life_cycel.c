#include "philo.h"

void *life_cycel(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    if(philo->data->n_philo > 1)
        usleep(500);
    if (philo->data->n_philo == 1)
    {
        printf("%d %d %s\n", 0, 1, "has taken a fork");
        if(usleep(philo->data->t_to_die * 1000) == -1)
            printf("usleep has filie !!");
        else
            printf("%d %d %s\n", philo->data->t_to_die, 1, "died");
        return NULL;
    }
    
    while (1)
    {
        take_forks(philo);
        etaing(philo);
        sleeping(philo);
        thinking(philo);
    }

    return NULL;
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
