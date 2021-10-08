/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:33:18 by dason             #+#    #+#             */
/*   Updated: 2021/10/06 21:33:19 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	view_x(t_info *info)
{
	if (HEIGHT / PIXEL > info->map_data->map_height
		|| info->pos_x - ((HEIGHT / PIXEL) / 2) < 0)
		return (0);
	return (info->pos_x - ((HEIGHT / PIXEL) / 2));
}

int	view_y(t_info *info)
{
	if (WIDTH / PIXEL > info->map_data->map_width
		|| info->pos_y - ((WIDTH / PIXEL) / 2) < 0)
		return (0);
	return (info->pos_y - ((WIDTH / PIXEL) / 2));
}
