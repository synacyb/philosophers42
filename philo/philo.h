#ifndef PHILO_H
#define PHILO_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define invalid 0
#define valid 1
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
    int id;
    pthread_t   thread;

}t_philo;
//all prototypes !

long	ft_atoi(const char *nptr);
void    set_enum(t_enum *data);
int     check_args(char **args);
void    set_data(t_data *data, char **args, int ac);
#endif