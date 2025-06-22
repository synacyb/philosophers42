/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:08:20 by ayadouay          #+#    #+#             */
/*   Updated: 2025/06/22 18:25:20 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (check_args(av) == INVALID)
		{
			printf("Invalid Args !\n");
			return (1);
		}
		if (set_data(&data, av, ac) == 1)
			return (EXIT_FAILURE);
		init_philos(&data);
		create_threads(&data);
		ft_clean(&data);
	}
	else
	{
		printf("pls enter n_philos + t_die + t_eat + t_sleep \
+ n_t_must_eat(opional)\n");
		return (1);
	}
}
