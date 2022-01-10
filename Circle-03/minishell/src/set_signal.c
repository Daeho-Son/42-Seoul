/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:57:50 by jongpark          #+#    #+#             */
/*   Updated: 2021/12/17 12:05:15 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_signal(int sig)
{
	if (sig == SIGQUIT)
	{
		return ;
	}
	else if (sig == SIGINT)
	{
		exit(STAT_CTRL_C);
	}
}

void	handle_signal_non_builtin(int signo)
{
	if (signo == SIGQUIT)
	{
		printf("^\\Quit: 3\n");
	}
	if (signo == SIGINT)
	{
		printf("^C\n");
	}
}

void	set_signal_child(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
}

void	set_signal_non_built_in(void)
{
	signal(SIGINT, handle_signal_non_builtin);
	signal(SIGQUIT, handle_signal_non_builtin);
}

void	set_stty(t_info *info)
{
	tcgetattr(STDOUT_FILENO, &info->orig_term);
	tcgetattr(STDOUT_FILENO, &info->new_term);
	info->new_term.c_lflag &= (~ECHOCTL);
	tcsetattr(STDOUT_FILENO, TCSANOW, &info->new_term);
}
