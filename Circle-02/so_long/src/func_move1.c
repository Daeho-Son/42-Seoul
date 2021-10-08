/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_move1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:14:16 by dason             #+#    #+#             */
/*   Updated: 2021/10/04 20:14:17 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_w(t_info *info)
{
	int		status;

	status = check_move(info, info->pos_x - 1, info->pos_y);
	if (status == 1)
	{
		info->map_data->map[info->pos_x][info->pos_y] = '0';
		info->map_data->map[info->pos_x - 1][info->pos_y] = 'P';
		info->pos_x--;
		movement(info);
	}
}

void	move_s(t_info *info)
{
	int		status;

	status = check_move(info, info->pos_x + 1, info->pos_y);
	if (status == 1)
	{
		info->map_data->map[info->pos_x][info->pos_y] = '0';
		info->map_data->map[info->pos_x + 1][info->pos_y] = 'P';
		info->pos_x++;
		movement(info);
	}
}

void	move_a(t_info *info)
{
	int		status;

	status = check_move(info, info->pos_x, info->pos_y - 1);
	if (status == 1)
	{
		info->map_data->map[info->pos_x][info->pos_y] = '0';
		info->map_data->map[info->pos_x][info->pos_y - 1] = 'P';
		info->pos_y--;
		movement(info);
	}
}

void	move_d(t_info *info)
{
	int		status;

	status = check_move(info, info->pos_x, info->pos_y + 1);
	if (status == 1)
	{
		info->map_data->map[info->pos_x][info->pos_y] = '0';
		info->map_data->map[info->pos_x][info->pos_y + 1] = 'P';
		info->pos_y++;
		movement(info);
	}
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit_window(info);
	else if (keycode == KEY_W)
		move_w(info);
	else if (keycode == KEY_S)
		move_s(info);
	else if (keycode == KEY_A)
		move_a(info);
	else if (keycode == KEY_D)
		move_d(info);
	return (0);
}
