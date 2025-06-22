/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:08:35 by ayadouay          #+#    #+#             */
/*   Updated: 2025/06/22 18:37:20 by ayadouay         ###   ########.fr       */
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

int	check_number_of_philo(char **args)
{
	int	n_philo;
	int	t_to_d;
	int	t_to_et;
	int	t_to_slep;

	n_philo = ft_atoi(args[1]);
	if (n_philo == 0)
		return (INVALID);
	t_to_d = ft_atoi(args[2]);
	if (t_to_d == 0)
		return (INVALID);
	t_to_et = ft_atoi(args[3]);
	if (t_to_et == 0)
		return (INVALID);
	t_to_slep = ft_atoi(args[4]);
	if (t_to_slep == 0)
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
	if (check_number_of_philo(args) == INVALID)
		return (INVALID);
	return (VALID);
}
