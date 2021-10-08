/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:09:00 by dason             #+#    #+#             */
/*   Updated: 2021/06/23 20:49:41 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	func_push(t_stack *src, t_stack *dest)
{
	t_node	*new_node;

	new_node = pop(src);
	if (!new_node)
		return ;
	if (!dest->top)
		dest->top = new_node;
	else
	{
		new_node->next = dest->top;
		dest->top = new_node;
	}
	dest->count += 1;
}

void	func_reverse_rotate(t_stack *stack)
{
	t_node	*top;
	t_node	*bottom;
	t_node	*tmp;

	if (!stack->top || stack->count == 1)
		return ;
	top = stack->top;
	bottom = get_last_node(stack);
	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->next == bottom)
			break ;
		tmp = tmp->next;
	}
	bottom->next = top;
	stack->top = bottom;
	tmp->next = NULL;
}

void	func_rotate(t_stack *stack)
{
	t_node	*top;
	t_node	*bottom;

	if (!stack->top || stack->count == 1)
		return ;
	top = stack->top;
	bottom = get_last_node(stack);
	stack->top = top->next;
	bottom->next = top;
	top->next = NULL;
}

void	func_swap(t_stack *stack)
{
	t_node	*target1;
	t_node	*target2;

	target1 = stack->top;
	if (!target1)
		return ;
	target2 = target1->next;
	if (!target2)
		return ;
	stack->top = target2;
	target1->next = target2->next;
	target2->next = target1;
}
