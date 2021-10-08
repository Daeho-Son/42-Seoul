/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:09:39 by dason             #+#    #+#             */
/*   Updated: 2021/06/29 17:46:29 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

int	check_sort_status(t_stack *stack)
{
	t_node	*top;
	t_node	*node;
	int		tmp;

	top = stack->top;
	if (!top)
		return (0);
	node = top->next;
	tmp = stack->top->data;
	if (!node)
		return (1);
	while (node->next)
	{
		if (tmp > node->data)
			return (0);
		tmp = node->data;
		node = node->next;
	}
	if (tmp > node->data)
		return (0);
	return (1);
}
