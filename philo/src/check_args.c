/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:08:35 by ayadouay          #+#    #+#             */
/*   Updated: 2025/06/19 14:02:31 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_valid_arguments(char *nptr)
{
	if (ft_atoi(nptr) == 2147483649)
		return (invalid);
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		return (invalid);
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

int	check_number_of_philo(char *arg1)
{
	int	n_philo;

	n_philo = ft_atoi(arg1);
	if (n_philo <= 0)
		return (invalid);
	return (valid);
}

int	check_args(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (ft_valid_arguments(args[i]) == invalid)
			return (invalid);
		i++;
	}
	if (check_number_of_philo(args[1]) == invalid)
		return (invalid);
	return (valid);
}
