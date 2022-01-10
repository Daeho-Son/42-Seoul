/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:59:56 by jongpark          #+#    #+#             */
/*   Updated: 2021/12/27 13:16:05 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*make_prompt(void)
{
	char	cwd_path[PATH_LENGTH];

	return (ft_strjoin(getcwd(cwd_path, PATH_LENGTH), " > "));
}

int	get_exit_result(int stat)
{
	int	result;

	if ((stat & 255) > 0)
		result = (stat & 255) + 128;
	else
		result = stat >> 8;
	return (result);
}

void	readline_child(int *ipc_pipe)
{
	char	*buf;
	char	*prompt;

	set_signal_child();
	prompt = make_prompt();
	buf = readline(prompt);
	free(prompt);
	if (buf == NULL)
		exit(STAT_CTRL_D);
	write(ipc_pipe[1], buf, ft_strlen(buf) + 1);
	exit(0);
}

char	*wait_child(int *ipc_pipe, t_info *info)
{
	char	*buf;
	int		stat;

	wait(&stat);
	if (get_exit_result(stat) == STAT_CTRL_D)
	{
		tcsetattr(STDOUT_FILENO, TCSAFLUSH, &info->orig_term);
		ft_exit(NULL, info);
		return (NULL);
	}
	if (get_exit_result(stat) == STAT_CTRL_C)
	{
		info->exit_status = 1;
		return (NULL);
	}
	buf = (char *)malloc(INPUT_BUFFER_SIZE);
	read(ipc_pipe[0], buf, INPUT_BUFFER_SIZE);
	return (buf);
}

char	*get_user_input(t_info *info)
{
	pid_t	pid;
	int		ipc_pipe[2];

	pipe(ipc_pipe);
	pid = fork();
	if (pid == 0)
		readline_child(ipc_pipe);
	else if (pid > 0)
		return (wait_child(ipc_pipe, info));
	else
	{
		printf("minishell: fork error");
		return (NULL);
	}
	return (NULL);
}
