/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_node_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:41:12 by dason             #+#    #+#             */
/*   Updated: 2021/12/24 11:26:09 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list_node.h"

t_list	*ft_create_list(int l_type, t_node *start_node)
{
	t_list	*new_list;

	new_list = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!new_list)
		exit(1);
	new_list->l_type = l_type;
	new_list->start_node = start_node;
	return (new_list);
}

t_node	*ft_create_node(int n_type, char *data)
{
	t_node	*new_node;

	if (!data)
		exit (1);
	new_node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->n_type = n_type;
	new_node->data = data;
	return (new_node);
}

void	ft_lstadd_back(t_list *list, t_list *new_list)
{
	if (!list)
		exit(1);
	while (list->next)
		list = list->next;
	new_list->prev = list;
	list->next = new_list;
}

void	ft_nodeadd_back(t_node *node, t_node *new_node)
{
	if (!node)
		exit(1);
	while (node->next)
		node = node->next;
	node->next = new_node;
}

t_list	*ft_get_last_list(t_list *list)
{
	if (!list)
		return (0);
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}
