#ifndef PHILO_H
#define PHILO_H
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

//data struct !!

typedef struct data
{
    int n_philo;
    int t_to_die;
    int t_to_eat;
    int t_to_sleep;
    int n_t_must_eat;
}t_data;

// state of philos !!
typedef struct enums
{
    int thinking;
    int sleeping;
    int eating;
    int dead;
}t_enum;

// data of philo
typedef struct philo
{
    int n_philo;
}t_philo;
//all prototypes !

int	ft_atoi(const char *nptr);
void    set_enum(t_enum *data);

#endif