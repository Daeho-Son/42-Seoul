/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:19:46 by dason             #+#    #+#             */
/*   Updated: 2021/12/27 13:06:04 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/executable.h"

void	excutable_child(t_list *list, char **envp, t_info *info)
{
	char	**argv;

	argv = make_argv_with_node(list);
	if (ft_strchr(list->start_node->data, '/'))
	{
		if (preprocess(list, info) == 0)
		{
			execve(argv[0], argv, envp);
			printf("minishell: %s: No such file or directory\n", argv[0]);
			exit (1);
		}
	}
	exit(127);
}

int	executable(t_list *list, char **envp, t_info *info)
{
	pid_t	pid;
	pid_t	wait_pid;
	int		exit_status;

	pid = fork();
	set_signal_non_built_in();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		excutable_child(list, envp, info);
	}
	else
	{
		wait_pid = wait(&pid);
		set_signal_parent();
		exit_status = get_exit_result(pid);
		if (wait_pid < 0 || exit_status == 127)
			return (-1);
		info->exit_status = exit_status;
		postprocess(info);
	}
	return (0);
}
