/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:16:26 by jongpark          #+#    #+#             */
/*   Updated: 2021/12/15 17:04:15 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unset.h"

int	unset(t_list *list, t_info *info)
{
	t_node	*node;
	int		flag;

	node = list->start_node->next;
	while (node)
	{
		if (has_equal(node->data) == false)
		{
			flag = remove_envp(node->data, info->envp, info);
			if (flag == -1)
				return (flag);
		}
		node = node->next;
	}
	info->exit_status = 0;
	return (0);
}
