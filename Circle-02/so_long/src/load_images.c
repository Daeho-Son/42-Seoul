/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:14:39 by dason             #+#    #+#             */
/*   Updated: 2021/10/04 20:22:08 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img_data	*get_img_data(t_info *info, char *map_dir)
{
	t_img_data	*img_data;

	img_data = (t_img_data *)malloc(sizeof(t_img_data));
	if (!img_data)
		error("Malloc assignment failed.");
	ft_memset(img_data, 0, sizeof(t_img_data));
	img_data->img = mlx_xpm_file_to_image(info->mlx, map_dir, \
			&img_data->img_width, &img_data->img_height);
	if (!img_data->img)
		error("Map file does not exist.");
	img_data->addr = mlx_get_data_addr(img_data->img, \
			&img_data->bits_per_pixel, \
			&img_data->line_length, &img_data->endian);
	return (img_data);
}

void	load_images(t_info *info)
{
	t_img_set	*img_set;

	img_set = info->img_set;
	img_set->player = get_img_data(info, "assets/textures/player.xpm");
	img_set->coin = get_img_data(info, "assets/textures/coin.xpm");
	img_set->exit = get_img_data(info, "assets/textures/exit.xpm");
	img_set->floor = get_img_data(info, "assets/textures/floor.xpm");
	img_set->wall = get_img_data(info, "assets/textures/wall.xpm");
}
