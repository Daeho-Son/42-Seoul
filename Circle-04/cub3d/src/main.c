/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:29:21 by hyun              #+#    #+#             */
/*   Updated: 2022/02/05 15:08:00 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

int	exit_game(t_info *info)
{
	info = NULL;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	ft_memset(&info, 0, sizeof(t_info));
	info.mlx_info.mlx = mlx_init();
	parse_map(argc, argv, &info);
	info.mlx_info.mlx_win = mlx_new_window(info.mlx_info.mlx,
			WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	mlx_key_hook(info.mlx_info.mlx_win, key_hook, &info);
	mlx_hook(info.mlx_info.mlx_win, 17, 0, exit_game, &info);
	render(&info);
	mlx_loop(info.mlx_info.mlx);
}
