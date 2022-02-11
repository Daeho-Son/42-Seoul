/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:43:04 by hyun              #+#    #+#             */
/*   Updated: 2022/01/24 23:54:02 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <stdlib.h>
# include <stdio.h>

# include "info.h"
# include "math.h"
# include "img.h"

# define RGB_RED 0x00FF0000
# define RGB_GREEN 0x0000FF00
# define RGB_BLUE 0x000000FF
# define RGB_WHITE 0x00FFFFFF
# define RGB_BLACK 0x00000000

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_raycast_result
{
	int		side;
	double	dist;
}			t_raycast_result;

typedef struct s_tex_vars
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			y;
	int			color;
	double		step;
	double		tex_pos;
	t_vec2		wall;
	t_vec2int	tex;
}			t_tex_vars;

void	cal_side_dist(t_info *info, t_vec2 dir, \
	t_vec2int *step, t_vec2 *side_dist);
void	cal_tex_color(t_tex_vars *vars, t_info *info, int side, t_vec2 dir);
void	set_tex_vars(t_tex_vars *vars, int side, t_vec2 dir);
int		*raycast(t_info *info, t_vec2 dir);

#endif
