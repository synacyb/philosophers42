/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:09:13 by ayadouay          #+#    #+#             */
/*   Updated: 2025/06/16 18:55:47 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    STATE_TAKE_FORK,
    STATE_EATING,
    STATE_SLEEPING,
    STATE_THINKING,
    STATE_DEAD
}   t_state;

typedef struct philo t_philo;
typedef struct data
{
    t_philo *philos;
    pthread_t watcher;
    int n_philo;
    int t_to_die;
    int t_to_eat;
    int t_to_sleep;
    int n_t_must_eat;
    time_t       start_time;
    int             stop;
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;
    pthread_mutex_t meal_mutex;
    pthread_mutex_t stop_mutex;
    t_state *state_data;
}   t_data;

// data of philo
typedef struct philo
{
    int             id;
    int             meals_eaten;
    time_t       last_meal;
    pthread_t       thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_data          *data;
}t_philo;
//all prototypes !

long	ft_atoi(const char *nptr);
int     check_args(char **args);
int    set_data(t_data *data, char **args, int ac);
time_t get_time(void);
void    init_philos(t_data *data);
void    create_threads(t_data *data);
int    ft_clean(t_data *data);
int    take_forks(t_philo *philo);
void    etaing(t_philo  *philo);
void    sleeping(t_philo *philo);
void    thinking(t_philo *philo);
void    ft_usleep(time_t time, t_data *data);
void	*ft_watcher(void *arg);
int ft_check_stop(t_data *data);
void	ft_log(t_philo *philo, int status);

#endif