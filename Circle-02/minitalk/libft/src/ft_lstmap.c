/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 22:15:35 by dason             #+#    #+#             */
/*   Updated: 2021/01/09 20:10:19 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*lst_map;
	t_list	*buf;

	if (!lst)
		return (NULL);
	lst_map = ft_lstnew(f(lst->content));
	if (!lst_map)
		return (NULL);
	buf = lst_map;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&lst_map, del);
			return (NULL);
		}
		buf->next = tmp;
		buf = tmp;
		lst = lst->next;
	}
	return (lst_map);
}
