#include "philo.h"

int one_philo_exist(t_data *data)
{
    if(data->n_philo == 1)
    {
        printf("%d %d %s\n", 0, 1, "has taken a fork");
        if(usleep(data->t_to_die * 1000) == -1)
        {
            printf("usleep has filie !!");
                return (1);
        }
        else
            printf("%d %d %s\n", data->t_to_die, 1, "died");
    }
    return 0;
}
int main(int ac, char **av)
{
    if(ac == 5 || ac == 6)
    {
        if(check_args(av) == invalid)
        {
            printf("pls n_philo should be 1 or more && all args should be pos-nbrs && arn't excced INT-MAX !!\n");
            return (1);
        }
        t_data data;
        set_data(&data, av, ac);
        if(ac == 5)
            if(one_philo_exist(&data) == 1)
                return 1;
    }
    else
    {
        printf("pls enter n_philos + t_die + t_eat + t_sleep + n_t_must_eat(opional)\n");
        return(1);
    }
}