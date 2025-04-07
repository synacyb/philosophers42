#ifndef PHILO_H
#define PHILO_H
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

//data struct !!

typedef struct data
{
    int n_philos;
    int t_to_die;
    int t_to_eat;
    int t_to_sleep;
    int n_t_must_eat;
}t_data;

//all prototypes !

int	ft_atoi(const char *nptr);

#endif