/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:08:31 by ayadouay          #+#    #+#             */
/*   Updated: 2025/06/22 12:26:21 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(time_t time, t_data *data)
{
	time_t	start;

	start = get_time();
	while (!ft_check_stop(data) && (get_time() - start) <= time)
	{
		if (ft_check_stop(data))
			break ;
		usleep(50);
	}
}
