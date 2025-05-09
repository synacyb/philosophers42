
#include "philo.h"

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
        if (set_data(&data, av, ac) == 1)
            return (EXIT_FAILURE);
        init_philos(&data);
        create_threads(&data);
        ft_clean(&data);
    }
    else
    {
        printf("pls enter n_philos + t_die + t_eat + t_sleep + n_t_must_eat(opional)\n");
        return(1);
    }
}