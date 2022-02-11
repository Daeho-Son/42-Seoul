/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:57:41 by dason             #+#    #+#             */
/*   Updated: 2022/02/09 13:08:20 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INFO_H
# define MLX_INFO_H

# define WIN_TITLE "cub3D"
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct s_mlx_info
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx_info;

#endif
