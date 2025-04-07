#include "philo.h"

void    set_enum(t_enum *data)
{
    data->thinking = 0;
    data->eating = 1;
    data->sleeping = 2;
    data->dead = 3;
}