/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:08:54 by dason             #+#    #+#             */
/*   Updated: 2022/02/04 22:11:28 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	draw_player_pixel(t_img *img, int x, int y)
{
	int		hx;
	int		hy;

	hy = y * MINIMAP_CELL_SIZE;
	while (hy < (y + 1) * MINIMAP_CELL_SIZE)
	{
		hx = x * MINIMAP_CELL_SIZE;
		while (hx < (x + 1) * MINIMAP_CELL_SIZE)
		{
			img->data[hy * WIN_WIDTH + hx] = GREEN;
			hx++;
		}
		hy++;
	}
}

void	draw_wall_pixel(t_img *img, int x, int y)
{
	int		hx;
	int		hy;

	hy = y * MINIMAP_CELL_SIZE;
	while (hy < (y + 1) * MINIMAP_CELL_SIZE)
	{
		hx = x * MINIMAP_CELL_SIZE;
		while (hx < (x + 1) * MINIMAP_CELL_SIZE)
		{
			img->data[hy * WIN_WIDTH + hx] = GREY;
			hx++;
		}
		hy++;
	}
}

void	draw_floor_pixel(t_img *img, int x, int y)
{
	int		hx;
	int		hy;

	hy = y * MINIMAP_CELL_SIZE;
	while (hy < (y + 1) * MINIMAP_CELL_SIZE)
	{
		hx = x * MINIMAP_CELL_SIZE;
		while (hx < (x + 1) * MINIMAP_CELL_SIZE)
		{
			img->data[hy * WIN_WIDTH + hx] = BLACK;
			hx++;
		}
		hy++;
	}
}
