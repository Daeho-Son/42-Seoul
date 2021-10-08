/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:14:27 by dason             #+#    #+#             */
/*   Updated: 2021/10/04 20:26:44 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img_data	*wall_coin_exit(t_info *info, char type)
{
	if (type == '1')
		return (info->img_set->wall);
	else if (type == 'C')
		return (info->img_set->coin);
	else if (type == 'E')
		return (info->img_set->exit);
	else if (type == 'P')
		return (info->img_set->player);
	return (info->img_set->floor);
}

int	paint(t_info *info)
{
	t_img_data	*img_data;
	int			v_x;
	int			v_y;
	int			x;
	int			y;

	v_x = view_x(info) - 1;
	x = 0;
	mlx_clear_window (info->mlx, info->win);
	while (info->map_data->map[++v_x][0] != '\0')
	{
		v_y = view_y(info) - 1;
		y = -1;
		while (info->map_data->map[v_x][++v_y] != '\0')
		{
			img_data = info->img_set->floor;
			mlx_put_image_to_window(info->mlx, info->win, img_data->img, \
					++y * img_data->img_width, x * img_data->img_height);
			img_data = wall_coin_exit(info, info->map_data->map[v_x][v_y]);
			mlx_put_image_to_window(info->mlx, info->win, img_data->img, \
					y * img_data->img_width, x * img_data->img_height);
		}
		x++;
	}
	return (0);
}
