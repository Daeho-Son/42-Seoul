/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:52:57 by dason             #+#    #+#             */
/*   Updated: 2021/12/24 14:19:07 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	parsing(t_list **list, char *str, t_info *info)
{
	t_list	*tmp_list;

	make_list(list, str);
	tmp_list = *list;
	while (tmp_list)
	{
		if (tmp_list->l_type == LTYPE_COMMAND)
			organize_node(tmp_list, info);
		tmp_list = tmp_list->next;
	}
}

int	parser(t_list **list, char *str, t_info *info)
{
	t_list	*tmp_list;

	str = organize_input_str(str);
	parsing(list, str, info);
	free(str);
	tmp_list = *list;
	if (!parser_handling_exception(tmp_list))
		return (-1);
	return (0);
}
