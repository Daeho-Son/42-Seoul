/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 13:09:26 by dason             #+#    #+#             */
/*   Updated: 2021/07/05 14:39:08 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"
#include <stdio.h>

static void	free_stack(t_stack **stack)
{
	t_node	*node;
	t_node	*tmp;

	node = (*stack)->top;
	if (node)
	{
		while (node->next)
		{
			tmp = node->next;
			free(node);
			node = NULL;
			node = tmp;
		}
		free(node);
		node = NULL;
	}
	free(*stack);
	*stack = NULL;
}

void	free_all(t_bundle **bundle, char ***s)
{
	int		index;

	free_stack(&(*bundle)->stack_a);
	free_stack(&(*bundle)->stack_b);
	free((*bundle)->arr);
	(*bundle)->arr = NULL;
	free(*bundle);
	*bundle = NULL;
	index = -1;
	if (s)
	{
		while ((*s)[++index])
		{
			free((*s)[index]);
			(*s)[index] = NULL;
		}
		free(*s);
		*s = NULL;
	}
}
