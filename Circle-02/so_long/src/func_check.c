/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:13:37 by dason             #+#    #+#             */
/*   Updated: 2021/10/04 20:14:53 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_move(t_info *info, int x, int y)
{
	if (info->map_data->map[x][y] == '1')
		return (-1);
	if (info->map_data->map[x][y] == 'C')
	{
		info->collection++;
		return (1);
	}
	if (info->map_data->map[x][y] == 'E')
	{
		if (info->collection == info->map_data->count_coin)
			exit(0);
		else
			return (-1);
	}
	return (1);
}
