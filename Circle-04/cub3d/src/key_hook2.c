/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:59:40 by hyun              #+#    #+#             */
/*   Updated: 2022/01/24 23:59:45 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hook.h"

int	turn_right(t_info *info)
{
	double	rot_speed;
	t_vec2	old_dir;
	t_vec2	old_right;
	t_vec2	old_fov;

	rot_speed = 0.3;
	printf("Key RIGHT pressed\n");
	old_dir = info->p_dir;
	old_right = info->p_right;
	old_fov = info->p_fov;
	info->p_dir.x = old_dir.x * cos(rot_speed) - old_dir.y * sin(rot_speed);
	info->p_dir.y = old_dir.x * sin(rot_speed) + old_dir.y * cos(rot_speed);
	info->p_right.x = \
		old_right.x * cos(rot_speed) - old_right.y * sin(rot_speed);
	info->p_right.y = \
		old_right.x * sin(rot_speed) + old_right.y * cos(rot_speed);
	info->p_fov.x = old_fov.x * cos(rot_speed) - old_fov.y * sin(rot_speed);
	info->p_fov.y = old_fov.x * sin(rot_speed) + old_fov.y * cos(rot_speed);
	render(info);
	return (0);
}

int	turn_left(t_info *info)
{
	double	rot_speed;
	t_vec2	old_dir;
	t_vec2	old_right;
	t_vec2	old_fov;

	rot_speed = 0.3;
	printf("Key LEFT pressed\n");
	old_dir = info->p_dir;
	old_right = info->p_right;
	old_fov = info->p_fov;
	info->p_dir.x = old_dir.x * cos(-rot_speed) - old_dir.y * sin(-rot_speed);
	info->p_dir.y = old_dir.x * sin(-rot_speed) + old_dir.y * cos(-rot_speed);
	info->p_right.x = \
		old_right.x * cos(-rot_speed) - old_right.y * sin(-rot_speed);
	info->p_right.y = \
		old_right.x * sin(-rot_speed) + old_right.y * cos(-rot_speed);
	info->p_fov.x = old_fov.x * cos(-rot_speed) - old_fov.y * sin(-rot_speed);
	info->p_fov.y = old_fov.x * sin(-rot_speed) + old_fov.y * cos(-rot_speed);
	render(info);
	return (0);
}
