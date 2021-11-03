/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:32:51 by dason             #+#    #+#             */
/*   Updated: 2021/10/30 16:32:52 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_routine_left(t_philo *philo)
{
	while (1)
	{
		action_eat_left(philo);
		action_sleep(philo);
		action_think(philo);
	}
}

void	*philo_routine_right(t_philo *philo)
{
	while (1)
	{
		action_eat_right(philo);
		action_sleep(philo);
		action_think(philo);
	}
}

int	philo_thread(t_philo *philo)
{
	int		num_of_philo;
	int		i;

	i = -1;
	num_of_philo = philo[0].info->num_of_philo;
	while (++i < num_of_philo)
	{
		if (philo[i].id != num_of_philo - 1)
		{
			if (pthread_create(&philo[i].thread, NULL, \
					(void *)philo_routine_right, &philo[i]) != 0)
				return (0);
		}
		else
		{
			if (pthread_create(&philo[i].thread, NULL, \
					(void *)philo_routine_left, &philo[i]) != 0)
				return (0);
		}
		usleep(100);
	}
	return (1);
}
