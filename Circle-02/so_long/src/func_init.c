/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:14:11 by dason             #+#    #+#             */
/*   Updated: 2021/10/04 20:19:23 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_pos(t_info *info)
{
	int		x;
	int		y;

	x = -1;
	while (info->map_data->map[++x][0] != '\0')
	{
		y = -1;
		while (info->map_data->map[x][++y] != '\0')
		{
			if (info->map_data->map[x][y] == 'P')
			{
				info->pos_x = x;
				info->pos_y = y;
				return ;
			}
		}
	}
}

static void	window_size(t_info *info)
{
	int		width;
	int		height;

	width = info->map_data->map_width;
	height = info->map_data->map_height;
	if (width * PIXEL >= WIDTH && height * PIXEL >= HEIGHT)
		info->win = mlx_new_window(info->mlx, \
				WIDTH, HEIGHT, WIN_TITLE);
	else if (width * PIXEL >= WIDTH && height * PIXEL < HEIGHT)
		info->win = mlx_new_window(info->mlx, \
				WIDTH, height * PIXEL, WIN_TITLE);
	else if (width * PIXEL < WIDTH && height * PIXEL >= HEIGHT)
		info->win = mlx_new_window(info->mlx, \
				width * PIXEL, HEIGHT, WIN_TITLE);
	else
		info->win = mlx_new_window(info->mlx, \
				width * PIXEL, height * PIXEL, WIN_TITLE);
}

t_info	*init_mlx(t_map_data *map_data)
{
	t_info		*info;
	t_img_set	*img_set;

	info = (t_info *)malloc(sizeof(t_info));
	img_set = (t_img_set *)malloc(sizeof(t_img_set));
	if (!info || !img_set)
		error("Malloc assignment failed.");
	ft_memset(info, 0, sizeof(t_info));
	ft_memset(img_set, 0, sizeof(t_img_set));
	info->mlx = mlx_init();
	info->map_data = map_data;
	info->img_set = img_set;
	get_pos(info);
	window_size(info);
	return (info);
}
