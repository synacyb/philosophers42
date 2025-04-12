#include "../philo.h"

void    set_data(t_data *data, char **args, int ac)
{
    int i;

    i = 0;
    data->n_philo = ft_atoi(args[1]);
    data->t_to_die = ft_atoi(args[2]);
    data->t_to_eat = ft_atoi(args[3]);
    data->t_to_sleep = ft_atoi(args[4]);
    if(ac == 6)
        data->n_t_must_eat = ft_atoi(args[5]);
    else
        data->n_t_must_eat = -1;
}