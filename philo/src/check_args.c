/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:08:35 by ayadouay          #+#    #+#             */
/*   Updated: 2025/06/21 14:29:11 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_valid_arguments(char *nptr)
{
	if (ft_atoi(nptr) == 2147483649)
		return (INVALID);
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		return (INVALID);
	else if (*nptr == '+')
	{
		nptr++;
		if (!(*nptr >= '0' && *nptr <= '9'))
			return (INVALID);
	}
	while (*nptr != '\0' && (*nptr >= '0' && *nptr <= '9'))
		nptr++;
	if (!*nptr)
		return (VALID);
	else
		return (INVALID);
}

int	check_number_of_philo(char *arg1)
{
	int	n_philo;

	n_philo = ft_atoi(arg1);
	if (n_philo <= 0)
		return (INVALID);
	return (VALID);
}

int	check_args(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (ft_valid_arguments(args[i]) == INVALID)
			return (INVALID);
		i++;
	}
	if (check_number_of_philo(args[1]) == INVALID)
		return (INVALID);
	return (VALID);
}
