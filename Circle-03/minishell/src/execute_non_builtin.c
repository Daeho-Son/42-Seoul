/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_non_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:02:23 by jongpark          #+#    #+#             */
/*   Updated: 2021/12/23 14:30:45 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*make_command(char	**argv, char *location)
{
	int		command_length;
	char	*command;

	command_length = strlen(argv[0]) + ft_strlen(location) + 1;
	command = (char *)ft_calloc(command_length, 1);
	if (command == NULL)
		return (NULL);
	ft_strlcpy(command, location, command_length);
	ft_strlcat(command, argv[0], command_length);
	return (command);
}

void	add_pipe_to_argv(char ***argv, t_info *info)
{
	char	str[8096];
	char	**new_argv;
	int		i;
	int		len;

	read(info->pipe_in[0], str, 8096);
	len = 0;
	while ((*argv)[len])
		len++;
	new_argv = (char **)ft_calloc(sizeof(char *) * (len + 2), 1);
	i = 0;
	while (i < len)
	{
		new_argv[i] = (*argv)[i];
		i++;
	}
	new_argv[i] = str;
	free(*argv);
	*argv = new_argv;
}

static void	when_is_path_run(char **argv, char **envp, char **paths)
{
	char	*new_s;
	char	*command;
	int		i;

	i = -1;
	while (paths[++i])
	{
		if (paths[i][ft_strlen(paths[i]) - 1] != '/')
		{
			new_s = ft_strjoin(paths[i], "/");
			free(paths[i]);
			paths[i] = new_s;
		}
		command = make_command(argv, paths[i]);
		execve(command, argv, envp);
		free(command);
	}
}

static int	execute(char **argv, char **envp)
{
	char	**paths;
	int		i;
	bool	is_path;

	is_path = false;
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(&envp[i][5], ':');
			is_path = true;
		}
	}
	if (is_path == true)
	{
		when_is_path_run(argv, envp, paths);
		free_double_pointer(&paths);
	}
	write(2, "minishell: ", 11);
	write(2, argv[0], ft_strlen(argv[0]));
	write(2, ": command not found\n", 20);
	exit(127);
}

int	execute_non_builtin(t_list *list, char **argv, char **envp, t_info *info)
{
	int		pid;
	pid_t	wait_pid;

	pid = fork();
	set_signal_non_built_in();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		if (preprocess(list, info) == 0)
			execute(argv, envp);
		exit(1);
	}
	else
	{
		wait_pid = wait(&pid);
		set_signal_parent();
		info->exit_status = get_exit_result(pid);
		if (wait_pid < 0)
			return (-1);
		postprocess(info);
	}
	free_double_pointer(&argv);
	return (0);
}
