/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:28:25 by dason             #+#    #+#             */
/*   Updated: 2021/12/07 11:28:26 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/free.h"

void	free_double_pointer(char ***s)
{
	int		i;

	i = -1;
	while ((*s)[++i])
	{
		free((*s)[i]);
		(*s)[i] = NULL;
	}
	free(*s);
	*s = NULL;
}

void	free_list(t_list *list)
{
	t_node	*node;
	t_node	*next_node;

	node = list->start_node;
	while (node)
	{
		next_node = node->next;
		free(node->data);
		node->data = NULL;
		free(node);
		node = next_node;
	}
	free(list);
}

void	free_list_node(t_list **list)
{
	t_list	*next_list;

	while (*list)
	{
		next_list = (*list)->next;
		free_list(*list);
		*list = next_list;
	}
	free(*list);
}
