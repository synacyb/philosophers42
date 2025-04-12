#include "../philo.h"

long long get_time(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000LL) + (time.tv_usec / 1000));
}