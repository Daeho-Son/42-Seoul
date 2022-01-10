/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:35:52 by hyun              #+#    #+#             */
/*   Updated: 2021/12/24 11:12:56 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_redirect_l1(t_list *list, t_info *info)
{
	info->has_redirect_l1 = true;
	if (list->next)
		info->l1_path = ft_strdup(list->next->start_node->data);
}

void	handle_redirect_l2(t_list *list, t_info *info)
{
	info->has_redirect_l2 = true;
	if (list->next)
		info->l2_eof_word = ft_strjoin(list->next->start_node->data, "\n");
}

void	handle_redirect_r1(t_list *list, t_info *info)
{
	info->has_redirect_r1 = true;
	if (list->next)
		info->r1_path = ft_strdup(list->next->start_node->data);
}

void	handle_redirect_r2(t_list *list, t_info *info)
{
	info->has_redirect_r2 = true;
	if (list->next)
		info->r2_path = ft_strdup(list->next->start_node->data);
}

void	handle_redirect(t_list *list, t_info *info)
{
	while (list)
	{
		if (list->l_type == LTYPE_PIPE)
		{
			pipe(info->pipe_in);
			info->has_pipe_in = true;
			break ;
		}
		if (list->l_type == LTYPE_REDIRECT_L1)
			handle_redirect_l1(list, info);
		if (list->l_type == LTYPE_REDIRECT_L2)
			handle_redirect_l2(list, info);
		if (list->l_type == LTYPE_REDIRECT_R1)
			handle_redirect_r1(list, info);
		if (list->l_type == LTYPE_REDIRECT_R2)
			handle_redirect_r2(list, info);
		list = list->next;
	}
}
