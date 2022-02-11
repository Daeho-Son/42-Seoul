/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:24:58 by dason             #+#    #+#             */
/*   Updated: 2022/01/25 16:59:13 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	error_exit(char *error_msg)
{
	ft_putstr_fd("Error Message: ", 2);
	ft_putstr_fd(error_msg, 2);
	exit(1);
}

bool	is_type_id(char *type_id)
{
	if (ft_strncmp("NO", type_id, 3) == 0)
		return (true);
	if (ft_strncmp("SO", type_id, 3) == 0)
		return (true);
	if (ft_strncmp("WE", type_id, 3) == 0)
		return (true);
	if (ft_strncmp("EA", type_id, 3) == 0)
		return (true);
	if (ft_strncmp("F", type_id, 2) == 0)
		return (true);
	if (ft_strncmp("C", type_id, 2) == 0)
		return (true);
	return (false);
}

int	get_kind_of_type(char *type_id)
{
	if (ft_strncmp("NO", type_id, 3) == 0)
		return (TYPE_NO);
	if (ft_strncmp("SO", type_id, 3) == 0)
		return (TYPE_SO);
	if (ft_strncmp("WE", type_id, 3) == 0)
		return (TYPE_WE);
	if (ft_strncmp("EA", type_id, 3) == 0)
		return (TYPE_EA);
	if (ft_strncmp("F", type_id, 2) == 0)
		return (TYPE_F);
	if (ft_strncmp("C", type_id, 2) == 0)
		return (TYPE_C);
	if (ft_strncmp("1", type_id, 1) == 0)
		return (TYPE_MAP);
	if (ft_strncmp(" ", type_id, 1) == 0)
		return (TYPE_MAP);
	if (ft_strncmp("0", type_id, 1) == 0)
		return (TYPE_MAP);
	return (TYPE_NONE);
}
