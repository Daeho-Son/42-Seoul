/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:31:57 by jongpark          #+#    #+#             */
/*   Updated: 2021/12/22 10:45:47 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/echo.h"

t_node	*check_flag(t_node *start_node, bool *has_n_flag)
{
	char	*data;

	if (start_node->next)
	{
		data = start_node->next->data;
		if (ft_strlen(data) == 2
			&& data[0] == '-' && data[1] == 'n')
		{
			*has_n_flag = true;
			return (start_node->next->next);
		}
	}
	*has_n_flag = false;
	return (start_node->next);
}

int	echo(t_list *list, t_info *info)
{
	bool	has_n_flag;
	t_node	*node;
	int		node_count;

	if (!list || list->l_type != LTYPE_COMMAND)
		return (-1);
	node = check_flag(list->start_node, &has_n_flag);
	node_count = 0;
	while (node)
	{
		if (ft_strlen(node->data))
		{
			if (node_count != 0)
				write(STDOUT_FILENO, " ", 1);
			write(STDOUT_FILENO, node->data, ft_strlen(node->data));
			++node_count;
		}
		node = node->next;
	}
	if (has_n_flag == false)
		write(1, "\n", 1);
	info->exit_status = 0;
	return (0);
}
