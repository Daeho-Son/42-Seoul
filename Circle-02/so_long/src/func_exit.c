/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:13:59 by dason             #+#    #+#             */
/*   Updated: 2021/10/04 20:14:01 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_window(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img_set->player);
	mlx_destroy_image(info->mlx, info->img_set->coin);
	mlx_destroy_image(info->mlx, info->img_set->exit);
	mlx_destroy_image(info->mlx, info->img_set->floor);
	mlx_destroy_image(info->mlx, info->img_set->wall);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
}
