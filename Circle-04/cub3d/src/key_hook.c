/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:31:33 by hyun              #+#    #+#             */
/*   Updated: 2022/02/09 13:30:10 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hook.h"

int	move_forward(t_info *info)
{
	t_vec2	dest;
	t_vec2	move_amount;

	move_amount.x = round(info->p_dir.x * 10) / 10;
	move_amount.y = round(info->p_dir.y * 10) / 10;
	dest = v2_plus(info->p_pos, move_amount);
	if ((int)round(dest.x * 10) % 10 == 0)
		dest.x += 0.1;
	if ((int)round(dest.y * 10) % 10 == 0)
		dest.y += 0.1;
	if (info->map_info.map[(int)(dest.y)][(int)(dest.x)] == FLOOR)
	{
		info->p_pos = dest;
		render(info);
	}
	printf("Key W pressed. p_pos(%f, %f)\n", info->p_pos.x, info->p_pos.y);
	return (0);
}

int	move_backward(t_info *info)
{
	t_vec2	dest;
	t_vec2	move_amount;

	move_amount.x = round(info->p_dir.x * 10) / 10;
	move_amount.y = round(info->p_dir.y * 10) / 10;
	dest = v2_minus(info->p_pos, move_amount);
	if ((int)round(dest.x * 10) % 10 == 0)
		dest.x += 0.1;
	if ((int)round(dest.y * 10) % 10 == 0)
		dest.y += 0.1;
	if (info->map_info.map[(int)(dest.y)][(int)(dest.x)] == FLOOR)
	{
		info->p_pos = dest;
		render(info);
	}
	printf("Key S pressed. p_pos(%f, %f)\n", info->p_pos.x, info->p_pos.y);
	return (0);
}

int	move_right(t_info *info)
{
	t_vec2	dest;
	t_vec2	move_amount;

	move_amount.x = round(info->p_right.x * 10) / 10;
	move_amount.y = round(info->p_right.y * 10) / 10;
	dest = v2_plus(info->p_pos, move_amount);
	if ((int)round(dest.x * 10) % 10 == 0)
		dest.x += 0.1;
	if ((int)round(dest.y * 10) % 10 == 0)
		dest.y += 0.1;
	if (info->map_info.map[(int)(dest.y)][(int)(dest.x)] == FLOOR)
	{
		info->p_pos = dest;
		render(info);
	}
	printf("Key D pressed. p_pos(%f, %f)\n", info->p_pos.x, info->p_pos.y);
	return (0);
}

int	move_left(t_info *info)
{
	t_vec2	dest;
	t_vec2	move_amount;

	move_amount.x = round(info->p_right.x * 10) / 10;
	move_amount.y = round(info->p_right.y * 10) / 10;
	dest = v2_minus(info->p_pos, move_amount);
	if ((int)round(dest.x * 10) % 10 == 0)
		dest.x += 0.1;
	if ((int)round(dest.y * 10) % 10 == 0)
		dest.y += 0.1;
	if (info->map_info.map[(int)(dest.y)][(int)(dest.x)] == FLOOR)
	{
		info->p_pos = dest;
		render(info);
	}
	printf("Key A pressed. p_pos(%f, %f)\n", info->p_pos.x, info->p_pos.y);
	return (0);
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
		return (move_forward(info));
	if (keycode == KEY_S)
		return (move_backward(info));
	if (keycode == KEY_D)
		return (move_right(info));
	if (keycode == KEY_A)
		return (move_left(info));
	if (keycode == KEY_RIGHT)
		return (turn_right(info));
	if (keycode == KEY_LEFT)
		return (turn_left(info));
	return (0);
}
