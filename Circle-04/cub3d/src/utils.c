/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:24:58 by dason             #+#    #+#             */
/*   Updated: 2022/02/05 14:39:41 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_double_pointer(char ***s)
{
	int		i;

	i = -1;
	while ((*s)[++i])
	{
		free((*s)[i]);
		(*s)[i] = NULL;
	}
	free(*s);
	*s = NULL;
}

void	free_info(t_info *info)
{
	void	*mlx;
	void	*win;

	mlx = info->mlx_info.mlx;
	win = info->mlx_info.mlx_win;
	mlx_destroy_image(mlx, info->map_info.no_texture);
	mlx_destroy_image(mlx, info->map_info.so_texture);
	mlx_destroy_image(mlx, info->map_info.we_texture);
	mlx_destroy_image(mlx, info->map_info.ea_texture);
	mlx_destroy_window(mlx, win);
}
