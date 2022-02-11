/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:39:45 by hyun              #+#    #+#             */
/*   Updated: 2022/01/24 23:57:27 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	*make_line(t_info *info, double dist, int side, t_vec2 dir)
{
	t_tex_vars	vars;
	int			*line;

	line = (int *)malloc(WIN_HEIGHT * sizeof(int));
	vars.line_height = (int)(WIN_HEIGHT / dist);
	if (side == 0)
		vars.wall.x = info->p_pos.y + dist * dir.y;
	else
		vars.wall.x = info->p_pos.x + dist * dir.x;
	set_tex_vars(&vars, side, dir);
	while (++vars.y < WIN_HEIGHT)
	{
		if (vars.y < vars.draw_start)
			line[vars.y] = info->map_info.ceiling_color;
		else if (vars.y > vars.draw_end)
			line[vars.y] = info->map_info.floor_color;
		else
		{
			cal_tex_color(&vars, info, side, dir);
			line[vars.y] = vars.color;
		}
	}
	return (line);
}

int	move_ray_x(t_vec2 *side_dist, t_vec2int *map_pos, \
	t_vec2 *delta_dist, t_vec2int *step)
{
	side_dist->x += delta_dist->x;
	map_pos->x += step->x;
	return (0);
}

int	move_ray_y(t_vec2 *side_dist, t_vec2int *map_pos, \
	t_vec2 *delta_dist, t_vec2int *step)
{
	side_dist->y += delta_dist->y;
	map_pos->y += step->y;
	return (1);
}

t_raycast_result	find_hit_dist(t_info *info, t_vec2 dir, \
	t_vec2 side_dist, t_vec2int step)
{
	t_vec2int			map_pos;
	t_vec2				delta_dist;
	t_raycast_result	result;

	result.side = 0;
	map_pos.x = (int)info->p_pos.x;
	map_pos.y = (int)info->p_pos.y;
	delta_dist.x = fabs(1 / dir.x);
	delta_dist.y = fabs(1 / dir.y);
	while (true)
	{
		if (side_dist.x < side_dist.y)
			result.side = move_ray_x(&side_dist, &map_pos, &delta_dist, &step);
		else
			result.side = move_ray_y(&side_dist, &map_pos, &delta_dist, &step);
		if (info->map_info.map[map_pos.y][map_pos.x] != FLOOR)
			break ;
	}
	if (result.side == 0)
		result.dist = (map_pos.x - info->p_pos.x + (1 - step.x) / 2) / dir.x;
	else
		result.dist = (map_pos.y - info->p_pos.y + (1 - step.y) / 2) / dir.y;
	return (result);
}

int	*raycast(t_info *info, t_vec2 dir)
{
	t_vec2int			step;
	t_vec2				side_dist;
	t_raycast_result	result;

	cal_side_dist(info, dir, &step, &side_dist);
	result = find_hit_dist(info, dir, side_dist, step);
	return (make_line(info, result.dist, result.side, dir));
}
