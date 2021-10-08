/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:13:58 by dason             #+#    #+#             */
/*   Updated: 2021/07/16 18:27:48 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	g_client_pid = -1;
static int	g_binary = 0;

void	sigusr1_handler(int sig, siginfo_t *info, void *context)
{
	g_client_pid = info->si_pid;
	g_binary = (g_binary * 10) + 0;
}

void	sigusr2_handler(int sig, siginfo_t *info, void *context)
{
	g_client_pid = info->si_pid;
	g_binary = (g_binary * 10) + 1;
}

static void	init_sig(void)
{
	struct sigaction	usr1_new;
	struct sigaction	usr1_old;
	struct sigaction	usr2_new;
	struct sigaction	usr2_old;

	usr1_new.sa_flags = SA_SIGINFO;
	usr1_new.sa_sigaction = sigusr1_handler;
	sigemptyset(&usr1_new.sa_mask);
	usr2_new.sa_flags = SA_SIGINFO;
	usr2_new.sa_sigaction = sigusr2_handler;
	sigemptyset(&usr2_new.sa_mask);
	sigaction(SIGUSR1, &usr1_new, &usr1_old);
	sigaction(SIGUSR2, &usr2_new, &usr2_old);
}

int	main(void)
{
	int		count;

	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	init_sig();
	count = -1;
	g_binary = 0;
	while (1)
	{
		pause();
		usleep(10);
		if (++count == 7)
		{
			print_msg(g_binary);
			g_binary = 0;
			count = -1;
		}
		usleep(10);
		kill(g_client_pid, SIGUSR1);
	}
	return (0);
}
