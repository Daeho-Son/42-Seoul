/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:08:55 by dason             #+#    #+#             */
/*   Updated: 2021/06/29 14:57:45 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (!stack->top)
		return (0);
	node = stack->top;
	stack->top = stack->top->next;
	node->next = NULL;
	stack->count -= 1;
	return (node);
}

void	add_last_node(t_stack *stack, t_node *new_node)
{
	t_node	*node;

	if (!new_node)
		return ;
	node = stack->top;
	if (!node)
		stack->top = new_node;
	else
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	stack->count += 1;
}

t_node	*get_last_node(t_stack *stack)
{
	t_node	*node;

	if (!stack->top)
		return (0);
	node = stack->top;
	while (node->next)
		node = node->next;
	return (node);
}
