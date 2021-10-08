/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:20:19 by dason             #+#    #+#             */
/*   Updated: 2021/10/04 20:18:27 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include "../includes/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define PIXEL 64
# define WIDTH 1280
# define HEIGHT	720
# define WIN_TITLE "so_long"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_map_data
{
	int		map_width;
	int		map_height;
	int		count_player;
	int		count_coin;
	int		count_exit;
	char	**map;
}			t_map_data;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}			t_img_data;

typedef struct s_img_set
{
	struct s_img_data	*player;
	struct s_img_data	*coin;
	struct s_img_data	*exit;
	struct s_img_data	*floor;
	struct s_img_data	*wall;
}						t_img_set;

typedef struct s_info
{
	void				*mlx;
	void				*win;
	struct s_img_set	*img_set;
	struct s_map_data	*map_data;
	int					pos_x;
	int					pos_y;
	int					collection;
	int					move_count;
	int					exit_status;
}						t_info;

/*
**	ERROR, EXIT_WINDOW
*/
void		error(char *msg);
int			exit_window(t_info *info);

/*
**	MAP
*/
t_map_data	*load_map(int argc, char *argv[]);
void		print_map(t_info *info);

/*
**	MLX
*/
t_info		*init_mlx(t_map_data *map_data);

/*
**	IMAGE
*/
t_img_data	*get_img_data(t_info *info, char *map_dir);
void		load_images(t_info *info);
int			paint(t_info *info);

/*
**	MOVE
*/
int			key_hook(int keycode, t_info *info);
int			check_move(t_info *info, int x, int y);
int			movement(t_info *info);

/*
**	VIEW
*/
int			view_x(t_info *info);
int			view_y(t_info *info);

#endif
