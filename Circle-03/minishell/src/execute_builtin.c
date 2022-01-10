/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:31:26 by jongpark          #+#    #+#             */
/*   Updated: 2021/12/23 13:17:17 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	is_builtin(t_list *list)
{
	if (ft_strncmp(list->start_node->data, "env", 4) == 0 || \
	ft_strncmp(list->start_node->data, "export", 7) == 0 || \
	ft_strncmp(list->start_node->data, "unset", 6) == 0 || \
	ft_strncmp(list->start_node->data, "pwd", 4) == 0 || \
	ft_strncmp(list->start_node->data, "cd", 3) == 0 || \
	ft_strncmp(list->start_node->data, "echo", 5) == 0 || \
	ft_strncmp(list->start_node->data, "exit", 5) == 0)
		return (true);
	return (false);
}

void	exec_builtin(t_list *list, t_info *info)
{
	if (ft_strncmp(list->start_node->data, "env", 4) == 0)
		env(info);
	else if (ft_strncmp(list->start_node->data, "export", 7) == 0)
		ft_export(list, info);
	else if (ft_strncmp(list->start_node->data, "unset", 6) == 0)
		unset(list, info);
	else if (ft_strncmp(list->start_node->data, "pwd", 4) == 0)
		pwd(info);
	else if (ft_strncmp(list->start_node->data, "cd", 3) == 0)
		cd(list, info);
	else if (ft_strncmp(list->start_node->data, "echo", 5) == 0)
		echo(list, info);
	else if (ft_strncmp(list->start_node->data, "exit", 5) == 0)
		ft_exit(list, info);
}

int	try_exec_builtin(t_list *list, t_info *info)
{
	if (is_builtin(list) == false)
		return (-1);
	if (preprocess(list, info) == 0)
		exec_builtin(list, info);
	postprocess_builtin(list, info);
	return (0);
}
