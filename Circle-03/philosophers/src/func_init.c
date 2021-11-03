/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:32:55 by dason             #+#    #+#             */
/*   Updated: 2021/10/30 16:32:56 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_info(t_info *info, int argc, char **argv)
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	printer;
	int				i;

	info->start_time = get_ms();
	info->num_of_philo = get_num(argv[1]);
	info->time_to_die = get_num(argv[2]);
	info->time_to_eat = get_num(argv[3]);
	info->time_to_sleep = get_num(argv[4]);
	if (argc == 6)
		info->philo_must_eat = get_num(argv[5]);
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* info->num_of_philo);
	if (!forks)
		return (0);
	memset(forks, 0, sizeof(pthread_mutex_t) * info->num_of_philo);
	i = -1;
	while (++i < info->num_of_philo)
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (0);
	info->forks = forks;
	if (pthread_mutex_init(&printer, NULL) != 0)
		return (0);
	info->printer = printer;
	return (1);
}

static t_philo	*init_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	if (!philo)
		return (0);
	memset(philo, 0, sizeof(t_philo) * info->num_of_philo);
	i = -1;
	while (++i < info->num_of_philo)
	{
		philo[i].id = i;
		philo[i].left_fork = i;
		if (i == 0)
			philo[i].right_fork = info->num_of_philo - 1;
		else
			philo[i].right_fork = i - 1;
		philo[i].last_eat_time = get_ms();
		philo[i].info = info;
	}
	return (philo);
}

t_philo	*init(int argc, char **argv)
{
	t_philo	*philo;
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (0);
	memset(info, 0, sizeof(t_info));
	if (!init_info(info, argc, argv))
		return (0);
	philo = init_philo(info);
	return (philo);
}
