/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:56:45 by dason             #+#    #+#             */
/*   Updated: 2021/10/04 20:25:41 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_map_data	*map_data;
	t_info		*info;

	map_data = load_map(argc, argv);
	info = init_mlx(map_data);
	load_images(info);
	mlx_key_hook(info->win, key_hook, info);
	mlx_hook(info->win, 17, 0, exit_window, info);
	mlx_loop_hook(info->mlx, paint, info);
	mlx_loop(info->mlx);
	return (0);
}
