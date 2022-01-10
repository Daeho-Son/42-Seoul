/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:56:28 by dason             #+#    #+#             */
/*   Updated: 2021/12/16 16:11:30 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	make_info(t_info *info, char **envp)
{
	ft_memset(info, 0, sizeof(t_info));
	info->envp = dup_envp(envp);
	info->has_pipe_in = false;
	info->stdout_copy = dup(STDOUT_FILENO);
	info->stdin_copy = dup(STDIN_FILENO);
	return (0);
}

int	init_minishell(t_info *info, char **envp, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (make_info(info, envp) == -1)
		return (-1);
	set_signal_parent();
	set_stty(info);
	return (0);
}
