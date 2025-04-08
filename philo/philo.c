#include "philo.h"

void    print_msg(char  *str)
{
    int i = 0;

    while(str[i])
        write(1, &str[i++], 1);
}

int	ft_valid_arguments(char *nptr)
{
	if (ft_atoi(nptr) == 2147483649)
		return (invalid);
    while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
    if(*nptr == '-')
        return(invalid);
	else if (*nptr == '+')
	{
		nptr++;
		if (!(*nptr >= '0' && *nptr <= '9'))
			return (invalid);
	}
	while (*nptr != '\0' && (*nptr >= '0' && *nptr <= '9'))
		nptr++;
	if (!*nptr)
		return (valid);
	else
		return (invalid);
}
int    check_args(char **args)
{
    int i = 1;
    while (args[i])
    {
        if(ft_valid_arguments(args[i]) == invalid)
            return(invalid);
        i++;
    }
    return (valid);
}
int main(int ac, char **av)
{
    if(ac == 5 || ac == 6)
    {
        if(check_args(av) == invalid)
        {
            print_msg("pls all args should be pos-nbrs && arn't excced INT-MAX !!\n");
            return (1);
        }
        print_msg("all things is valid!");
    }
    else
    {
        print_msg("pls enter n_philos + t_to_die + t_to_eat n_t_must_eat(opional)\n");
        return(1);
    }
}