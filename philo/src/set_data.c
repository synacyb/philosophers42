#include "philo.h"


void    init_forks(t_data *data)
{
    int i;

    i = 0;

    while (i < data->n_philo)
        pthread_mutex_init(&data->forks[i++], NULL);
    
}

int    set_data(t_data *data, char **args, int ac)
{
    data->n_philo = ft_atoi(args[1]);
    data->t_to_die = ft_atoi(args[2]);
    data->t_to_eat = ft_atoi(args[3]);
    data->t_to_sleep = ft_atoi(args[4]);
    if(ac == 6)
        data->n_t_must_eat = ft_atoi(args[5]);
    else
        data->n_t_must_eat = -1;

    // Allocate array forks
    data->forks = malloc(data->n_philo * sizeof(pthread_mutex_t));
    if (!data->forks)
        return (EXIT_FAILURE);
    init_forks(data);
    // Allocate array philos
    data->philos = malloc(sizeof(t_philo) * data->n_philo);
    if (!data->philos)
        return (EXIT_FAILURE);
    pthread_mutex_init(&data->print_mutex, NULL);
    pthread_mutex_init(&data->meal_mutex, NULL);
    pthread_mutex_init(&data->stop_mutex, NULL);
    return (EXIT_SUCCESS);
}

int    ft_clean(t_data *data)
{
    free(data->forks);
    free(data->philos);
    return (EXIT_SUCCESS);
}
