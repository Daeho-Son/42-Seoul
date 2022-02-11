/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:55:21 by hyun              #+#    #+#             */
/*   Updated: 2022/02/09 20:45:37 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	cal_tex_color(t_tex_vars *vars, t_info *info, int side, t_vec2 dir)
{
	vars->tex.y = (int)vars->tex_pos & (TEX_HEIGHT - 1);
	vars->tex_pos += vars->step;
	if (side == 1 && dir.y <= 0)
		vars->color = \
			info->map_info.so_texture[vars->tex.y * TEX_WIDTH + vars->tex.x];
	else if (side == 1 && dir.y > 0)
		vars->color = \
			info->map_info.no_texture[vars->tex.y * TEX_WIDTH + vars->tex.x];
	else if (side == 0 && dir.x >= 0)
		vars->color = \
			info->map_info.we_texture[vars->tex.y * TEX_WIDTH + vars->tex.x];
	else if (side == 0 && dir.x < 0)
		vars->color = \
			info->map_info.ea_texture[vars->tex.y * TEX_WIDTH + vars->tex.x];
}

void	set_tex_vars(t_tex_vars *vars, int side, t_vec2 dir)
{
	vars->draw_start = -vars->line_height / 2 + WIN_HEIGHT / 2;
	if (vars->draw_start < 0)
		vars->draw_start = 0;
	vars->draw_end = vars->line_height / 2 + WIN_HEIGHT / 2;
	vars->wall.x -= floor(vars->wall.x);
	vars->tex.x = (int)(vars->wall.x * TEX_WIDTH);
	if (side == 0 && dir.x > 0)
		vars->tex.x = TEX_WIDTH - vars->tex.x - 1;
	if (side == 1 && dir.y < 0)
		vars->tex.x = TEX_WIDTH - vars->tex.x - 1;
	vars->step = 1.0 * TEX_HEIGHT / (double)vars->line_height;
	vars->tex_pos = (vars->draw_start - WIN_HEIGHT / 2 + vars->line_height / 2) \
		* vars->step;
	vars->y = -1;
}

void	cal_side_dist_x(t_info *info, t_vec2 dir, \
	t_vec2int *step, t_vec2 *side_dist)
{
	t_vec2int	map_pos;
	t_vec2		delta_dist;

	map_pos.x = (int)info->p_pos.x;
	map_pos.y = (int)info->p_pos.y;
	delta_dist.x = fabs(1 / dir.x);
	delta_dist.y = fabs(1 / dir.y);
	if (dir.x < 0)
	{
		step->x = -1;
		side_dist->x = (info->p_pos.x - map_pos.x) * delta_dist.x;
	}
	else
	{
		step->x = 1;
		side_dist->x = (map_pos.x + 1.0 - info->p_pos.x) * delta_dist.x;
	}
}

void	cal_side_dist_y(t_info *info, t_vec2 dir, \
	t_vec2int *step, t_vec2 *side_dist)
{
	t_vec2int	map_pos;
	t_vec2		delta_dist;

	map_pos.x = (int)info->p_pos.x;
	map_pos.y = (int)info->p_pos.y;
	delta_dist.x = fabs(1 / dir.x);
	delta_dist.y = fabs(1 / dir.y);
	if (dir.y < 0)
	{
		step->y = -1;
		side_dist->y = (info->p_pos.y - map_pos.y) * delta_dist.y;
	}
	else
	{
		step->y = 1;
		side_dist->y = (map_pos.y + 1.0 - info->p_pos.y) * delta_dist.y;
	}
}

void	cal_side_dist(t_info *info, t_vec2 dir, \
	t_vec2int *step, t_vec2 *side_dist)
{
	cal_side_dist_x(info, dir, step, side_dist);
	cal_side_dist_y(info, dir, step, side_dist);
}
