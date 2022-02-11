/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:31:07 by dason             #+#    #+#             */
/*   Updated: 2022/02/04 22:08:27 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static bool	is_out_of_the_map(t_info *info, t_vec2 minimap_pos)
{
	int		x;
	int		y;

	x = minimap_pos.x;
	y = minimap_pos.y;
	if (y < 0 || x < 0)
		return (true);
	if (y >= info->map_info.map_height || x >= info->map_info.map_width)
		return (true);
	if (info->map_info.map[y][x] == ' ')
		return (true);
	return (false);
}

static void	draw_pixel(t_info *info, t_img *img, t_vec2 m_pos, t_vec2 s_pos)
{
	int		minimap_x;
	int		minimap_y;

	minimap_x = (int)m_pos.x;
	minimap_y = (int)m_pos.y;
	if (minimap_y == (int)info->p_pos.y && minimap_x == (int)info->p_pos.x)
		draw_player_pixel(img, s_pos.x, s_pos.y);
	else if (info->map_info.map[minimap_y][minimap_x] == '1')
		draw_wall_pixel(img, s_pos.x, s_pos.y);
	else
		draw_floor_pixel(img, s_pos.x, s_pos.y);
}

int	draw_minimap(t_info *info, t_img *img)
{
	t_vec2	mmap_pos;
	t_vec2	screen_pos;

	screen_pos.y = 0;
	mmap_pos.y = (int)info->p_pos.y - (MINIMAP_HEIGHT / 2) - 1;
	while (++mmap_pos.y <= (int)info->p_pos.y + (MINIMAP_HEIGHT / 2))
	{
		screen_pos.x = 0;
		mmap_pos.x = (int)info->p_pos.x - (MINIMAP_WIDTH / 2) - 1;
		while (++mmap_pos.x <= (int)info->p_pos.x + (MINIMAP_WIDTH / 2))
		{
			if (is_out_of_the_map(info, mmap_pos) == true)
			{
			}
			else if (info->map_info.map[(int)mmap_pos.y] == NULL || \
				info->map_info.map[(int)mmap_pos.y][(int)mmap_pos.x] == '\0')
				break ;
			else
				draw_pixel(info, img, mmap_pos, screen_pos);
			screen_pos.x++;
		}
		screen_pos.y++;
	}
	return (0);
}
