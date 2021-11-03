/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:32:10 by dason             #+#    #+#             */
/*   Updated: 2021/10/30 16:32:13 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_info
{
	int					num_of_philo;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	unsigned long long	philo_must_eat;
	pthread_mutex_t		*forks;
	pthread_mutex_t		printer;
	unsigned long long	start_time;
}						t_info;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					left_fork;
	int					right_fork;
	int					count_eat;
	unsigned long long	last_eat_time;
	struct s_info		*info;
}						t_philo;

/*
**	UTILS
*/
unsigned long long	get_ms(void);
unsigned long long	get_num(char *s);
size_t				ft_strlen(const char *s);
size_t				num_of_digit(unsigned long long n);

/*
**	ACTION
*/
void				action_eat_left(t_philo *philo);
void				action_eat_right(t_philo *philo);
void				action_sleep(t_philo *philo);
void				action_think(t_philo *philo);

/*
**	MAIN
*/
int					checker(int argc, char **argv);
t_philo				*init(int argc, char **argv);
int					philo_thread(t_philo *philo);
int					monitor(t_philo *philo);		

/*
**	RETURN
*/
int					return_time_to_die(unsigned long long time, int id);
int					return_full(void);

#endif
