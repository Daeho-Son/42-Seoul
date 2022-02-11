/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:31:50 by dason             #+#    #+#             */
/*   Updated: 2022/02/04 22:10:37 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# define MINIMAP_WIDTH 10
# define MINIMAP_HEIGHT 10
# define GREEN 0x00FF00
# define WHITE 0xFFFFFF
# define GREY 0xbcbcbc
# define BLACK 0x000000
# define MINIMAP_CELL_SIZE 10

# include "cub3d.h"
# include "info.h"
# include "img.h"
# include <stdio.h>
# include <stdbool.h>

int		draw_minimap(t_info *info, t_img *img);
void	draw_player_pixel(t_img *img, int x, int y);
void	draw_wall_pixel(t_img *img, int x, int y);
void	draw_floor_pixel(t_img *img, int x, int y);

#endif
