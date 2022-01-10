/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:03:07 by hyun              #+#    #+#             */
/*   Updated: 2021/12/24 15:39:53 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	preprocess_pipe_write(t_info *info)
{
	dup2(info->pipe_in[WRITE_END], STDOUT_FILENO);
	close(info->pipe_in[WRITE_END]);
}

void	preprocess_pipe_read(t_info *info)
{
	dup2(info->pipe_out[READ_END], STDIN_FILENO);
	close(info->pipe_out[READ_END]);
}

bool	has_pipe_before(t_list *list)
{
	while (list->prev)
	{
		if (list->prev->l_type == LTYPE_PIPE)
			return (true);
		if (list->prev->l_type == LTYPE_COMMAND)
			break ;
		list = list->prev;
	}
	return (false);
}

int	preprocess(t_list *list, t_info *info)
{
	if (info->has_redirect_l1)
	{
		if (preprocess_l1(info) == 1)
			return (1);
	}
	if (info->has_redirect_l2)
	{
		if (preprocess_l2(info) == 1)
			return (1);
	}
	if (info->has_redirect_r1)
		preprocess_r1(info);
	if (info->has_redirect_r2)
		preprocess_r2(info);
	if (info->has_pipe_in)
		preprocess_pipe_write(info);
	if (has_pipe_before(list))
		preprocess_pipe_read(info);
	return (0);
}
