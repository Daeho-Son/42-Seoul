/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postprocess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:15:21 by hyun              #+#    #+#             */
/*   Updated: 2021/12/13 19:21:38 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	postprocess(t_info *info)
{
	if (info->has_pipe_in)
	{
		close(info->pipe_in[WRITE_END]);
		info->has_pipe_in = false;
	}
	if (info->has_redirect_l1)
		info->has_redirect_l1 = false;
	if (info->has_redirect_l2)
		info->has_redirect_l2 = false;
	if (info->has_redirect_r1)
		info->has_redirect_r1 = false;
	if (info->has_redirect_r2)
		info->has_redirect_r2 = false;
}

void	postprocess_builtin_redirect(t_info *info)
{
	if (info->has_redirect_l1)
	{
		info->has_redirect_l1 = false;
		dup2(info->stdin_copy, STDIN_FILENO);
	}
	if (info->has_redirect_l2)
	{
		info->has_redirect_l2 = false;
		dup2(info->stdin_copy, STDIN_FILENO);
	}
	if (info->has_redirect_r1)
	{
		info->has_redirect_r1 = false;
		dup2(info->stdout_copy, STDOUT_FILENO);
	}
	if (info->has_redirect_r2)
	{
		info->has_redirect_r2 = false;
		dup2(info->stdout_copy, STDOUT_FILENO);
	}
}

void	postprocess_builtin(t_list *list, t_info *info)
{
	if (info->has_pipe_in)
	{
		close(info->pipe_in[WRITE_END]);
		info->has_pipe_in = false;
		dup2(info->stdout_copy, STDOUT_FILENO);
	}
	if (list->prev && list->prev->l_type == LTYPE_PIPE)
		dup2(info->stdin_copy, STDIN_FILENO);
	postprocess_builtin_redirect(info);
}
