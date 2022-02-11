/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:18:57 by hyun              #+#    #+#             */
/*   Updated: 2022/02/05 15:16:21 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_vec2	cal_dir(t_info *info, int camera_step)
{
	double	cam_x;
	t_vec2	dir;
	t_vec2	left_corner;

	cam_x = 2 * (double)camera_step / (double)WIN_WIDTH;
	left_corner = v2_minus(info->p_dir, info->p_fov);
	dir = v2_plus(left_corner, v2_scala(cam_x, info->p_fov));
	return (dir);
}

int	draw_line(t_img *img, int *line, int x)
{
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		img->data[y * WIN_WIDTH + x] = line[y];
	}
	return (0);
}

void	clear_img_win(t_info *info)
{
	mlx_clear_window(info->mlx_info.mlx, info->mlx_info.mlx_win);
	if (info->img)
	{
		mlx_destroy_image(info->mlx_info.mlx, info->img->img_ptr);
		free(info->img);
	}
}

int	render(t_info *info)
{
	int		w;
	t_vec2	dir;
	t_img	*img;
	int		*line;

	clear_img_win(info);
	img = (t_img *)malloc(sizeof(t_img));
	img->img_ptr = mlx_new_image(info->mlx_info.mlx, WIN_WIDTH, WIN_HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, \
		&img->size_l, &img->endian);
	w = -1;
	while (++w < WIN_WIDTH)
	{
		dir = cal_dir(info, w);
		line = raycast(info, dir);
		draw_line(img, line, w);
		free(line);
	}
	draw_minimap(info, img);
	mlx_put_image_to_window(info->mlx_info.mlx, info->mlx_info.mlx_win, \
		img->img_ptr, 0, 0);
	info->img = img;
	return (0);
}
