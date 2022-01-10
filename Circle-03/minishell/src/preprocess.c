/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:56:07 by hyun              #+#    #+#             */
/*   Updated: 2021/12/23 14:37:34 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	preprocess_l1(t_info *info)
{
	int	fd;

	fd = open(info->l1_path, O_RDONLY);
	if (fd > 0)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
		return (0);
	}
	else
	{
		printf("minishell: no such file or directory: %s\n", info->l1_path);
		return (1);
	}
}

void	preprocess_l2_child(t_info *info)
{
	char	*input;

	set_signal_child();
	while (true)
	{
		input = get_eof_input();
		if (!ft_strncmp(input, info->l2_eof_word,
				ft_strlen(info->l2_eof_word) + 1))
			break ;
		write(info->l2_pipe[WRITE_END], input, ft_strlen(input) + 1);
	}
	close(info->l2_pipe[WRITE_END]);
	close(info->l2_pipe[READ_END]);
	exit(0);
}

int	preprocess_l2(t_info *info)
{
	int		pid;

	pipe(info->l2_pipe);
	pid = fork();
	if (pid < 0)
	{
		printf("minishell: fork error\n");
		return (1);
	}
	if (pid == 0)
		preprocess_l2_child(info);
	else
	{
		wait(&pid);
		close(info->l2_pipe[WRITE_END]);
		pid = get_exit_result(pid);
		if (pid != STAT_CTRL_C)
			dup2(info->l2_pipe[READ_END], STDIN_FILENO);
		else
			return (1);
		close(info->l2_pipe[READ_END]);
	}
	return (0);
}

void	preprocess_r1(t_info *info)
{
	int	fd;

	fd = open(info->r1_path, O_WRONLY | O_CREAT | O_TRUNC, 0755);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	preprocess_r2(t_info *info)
{
	int	fd;

	fd = open(info->r2_path, O_WRONLY | O_CREAT | O_APPEND, 0755);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
