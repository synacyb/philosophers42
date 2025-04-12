#ifndef PHILO_H
#define PHILO_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#define invalid 0
#define valid 1
//data struct !!

// state of philos !!
typedef enum e_state
{
    STATE_THINKING,
    STATE_SLEEPING,
    STATE_EATING,
    STATE_DEAD
}   t_state;

typedef struct data
{
    int n_philo;
    int t_to_die;
    int t_to_eat;
    int t_to_sleep;
    int n_t_must_eat;
    long long       start_time;
    int             is_dead;
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;
    t_state *state_data;
}   t_data;

// data of philo
typedef struct philo
{
    int             id;
    int             meals_eaten;
    long long       last_meal;
    pthread_t       thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_data          *data;
}t_philo;
//all prototypes !

long	ft_atoi(const char *nptr);
int     check_args(char **args);
void    set_data(t_data *data, char **args, int ac);
long long get_time(void);
#endif