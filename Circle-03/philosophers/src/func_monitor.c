/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:32:53 by dason             #+#    #+#             */
/*   Updated: 2021/10/30 16:32:54 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	monitor(t_philo *philo)
{
	int					i;
	int					all_count_eat;
	unsigned long long	current_time;

	while (1)
	{
		i = -1;
		all_count_eat = 0;
		pthread_mutex_lock(&philo->info->printer);
		current_time = get_ms();
		while (++i < philo[0].info->num_of_philo)
		{
			if (current_time > philo[i].last_eat_time && get_ms() \
				- philo[i].last_eat_time > philo[i].info->time_to_die)
				return (return_time_to_die(current_time - \
						philo[i].info->start_time, philo[i].id + 1));
			if (philo[i].count_eat >= (int)philo[i].info->philo_must_eat)
				all_count_eat++;
		}
		if (philo[0].info->philo_must_eat
			&& (all_count_eat == philo[0].info->num_of_philo))
			return (return_full());
		pthread_mutex_unlock(&philo->info->printer);
	}
}
