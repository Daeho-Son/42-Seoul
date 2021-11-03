/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:32:27 by dason             #+#    #+#             */
/*   Updated: 2021/10/30 16:33:15 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	action_eat_left(t_philo *philo)
{
	unsigned long long	start_time;

	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->info->printer);
	printf("%03llums %d has taken a fork left\n", \
		get_ms() - philo->info->start_time, philo->id + 1);
	pthread_mutex_unlock(&philo->info->printer);
	pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
	pthread_mutex_lock(&philo->info->printer);
	printf("%03llums %d has taken a fork right\n", \
		get_ms() - philo->info->start_time, philo->id + 1);
	philo->count_eat++;
	printf("%03llums %d is eating: %d\n", \
		get_ms() - philo->info->start_time, philo->id + 1, philo->count_eat);
	pthread_mutex_unlock(&philo->info->printer);
	philo->last_eat_time = get_ms();
	start_time = get_ms();
	while (get_ms() - start_time < philo->info->time_to_eat)
	{
		usleep(100);
	}
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
}

void	action_eat_right(t_philo *philo)
{
	unsigned long long	start_time;

	pthread_mutex_lock(&(philo->info->forks[philo->right_fork]));
	pthread_mutex_lock(&philo->info->printer);
	printf("%03llums %d has taken a fork right\n", \
		get_ms() - philo->info->start_time, philo->id + 1);
	pthread_mutex_unlock(&philo->info->printer);
	pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->info->printer);
	printf("%03llums %d has taken a fork left\n", \
		get_ms() - philo->info->start_time, philo->id + 1);
	philo->count_eat++;
	printf("%03llums %d is eating: %d\n", \
		get_ms() - philo->info->start_time, philo->id + 1, philo->count_eat);
	pthread_mutex_unlock(&philo->info->printer);
	philo->last_eat_time = get_ms();
	start_time = get_ms();
	while (get_ms() - start_time < philo->info->time_to_eat)
	{
		usleep(100);
	}
	pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
}

void	action_sleep(t_philo *philo)
{
	unsigned long long	start_time;

	pthread_mutex_lock(&philo->info->printer);
	printf("%03llums %d is sleeping\n", \
		get_ms() - philo->info->start_time, philo->id + 1);
	pthread_mutex_unlock(&philo->info->printer);
	start_time = get_ms();
	while (get_ms() - start_time < philo->info->time_to_sleep)
	{
		usleep(100);
	}
}

void	action_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->printer);
	printf("%03llums %d is thinking\n", \
		get_ms() - philo->info->start_time, philo->id + 1);
	pthread_mutex_unlock(&philo->info->printer);
}
