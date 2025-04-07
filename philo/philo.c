#include "philo.h"

void    print_msg(char  *str)
{
    int i = 0;

    while(str[i])
        write(1, &str[i++], 1);
}
int main(int ac, char **av)
{
    if(ac == 5)
    {
        
    }
    else if(ac == 6)
    {

    }
    else
    {
        print_msg("pls enter n_philos + t_to_die + t_to_eat n_t_must_eat(opional)\n");
        return(1);
    }
}