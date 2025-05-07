#include "philo.h"

time_t get_time(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void    ft_usleep(time_t time)
{
    time_t	start;

	start = get_time();
	while ((get_time() - start) < time)
    {
        // TODO: Add a died check here by cecking the died flag (We must protect it by mutes)
        usleep(500);
    }
}

