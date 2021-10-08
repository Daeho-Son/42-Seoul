#ifndef PHILO_H
# define PHILO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_philo
{

}			t_philo;

typedef struct s_info
{
	int		nop;
	int		ttd;
	int		toe;
	int		tts;
	int		notepme;
	t_philo	*philo;
}			t_info;

/*
**	UTILS
*/
int		param_check(int ac, char **av);
t_info	*init(char **argv);

#endif
