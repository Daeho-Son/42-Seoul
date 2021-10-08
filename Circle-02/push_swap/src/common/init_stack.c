/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:09:04 by dason             #+#    #+#             */
/*   Updated: 2021/07/05 14:39:24 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

t_node	*create_node(char *s)
{
	t_node		*new_node;
	long long	data;
	int			index;
	int			minus;

	data = 0;
	index = -1;
	if (s[0] == '-')
	{
		minus = 1;
		index++;
	}
	else
		minus = 0;
	while (s[++index])
		data = data * 10 + s[index] - '0';
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!check_range(data) || !new_node)
		return (0);
	if (minus)
		new_node->data = (int)data * (-1);
	else
		new_node->data = (int)data;
	new_node->next = NULL;
	return (new_node);
}

int	init_stack(t_stack **stack, char name, char **s)
{
	t_stack	*new_stack;
	t_node	*node;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (0);
	new_stack->name = name;
	new_stack->top = NULL;
	new_stack->count = 0;
	new_stack->current = 0;
	if (s != NULL)
	{
		while (*s)
		{
			node = create_node(*s++);
			if (!node)
				return (0);
			add_last_node(new_stack, node);
		}
	}
	*stack = new_stack;
	return (1);
}
