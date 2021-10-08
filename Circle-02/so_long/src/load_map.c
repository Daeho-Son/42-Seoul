/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:14:44 by dason             #+#    #+#             */
/*   Updated: 2021/10/04 20:24:55 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

static void	read_map(t_map_data *map_data, char *argv[])
{
	int		fd;
	char	buff[1];

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("Map file does not exist.");
	ft_putendl_fd("# Map File", 1);
	while (read(fd, buff, 1) > 0)
	{
		ft_putstr_fd(buff, 1);
		map_data->map_width++;
		if (*buff == '\n')
			map_data->map_height++;
		if (*buff == 'P')
			map_data->count_player++;
		if (*buff == 'C')
			map_data->count_coin++;
		if (*buff == 'E')
			map_data->count_exit++;
	}
	ft_putchar_fd('\n', 1);
	map_data->map_width = (map_data->map_width - map_data->map_height) \
						  / map_data->map_height;
	close(fd);
}

static void	get_map(char *argv[], t_map_data *map_data)
{
	int			fd;
	char		**map;
	int			index;

	map = (char **)ft_calloc(map_data->map_height + 1, sizeof(char *));
	if (!map)
		error("malloc assignment failed.");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("There's no file.");
	index = 0;
	while (get_next_line(fd, &(map[index])) > 0)
	{
		if ((int) ft_strlen(map[index]) != map_data->map_width)
			error("This map is not a rectangle.");
		index++;
	}
	map_data->map = map;
	close(fd);
}

static int	check_wall(t_map_data *map_data)
{
	char	**map;
	int		map_height;
	int		map_width;

	map = map_data->map;
	map_height = 0;
	while (map[map_height][0] != '\0')
	{
		map_width = 0;
		while (map[map_height][map_width])
		{
			if ((map_height == 0 || map_height == map_data->map_height - 1)
				&& map[map_height][map_width] != 1 + '0')
				return (0);
			if (map_height != 0 && map_height != map_data->map_height - 1
				&& (map[map_height][0] != 1 + '0'
				|| map[map_height][map_data->map_width - 1] != 1 + '0'))
				return (0);
			map_width++;
		}
		map_height++;
	}
	return (1);
}

static void	check_map_error(t_map_data *map_data)
{
	if (!check_wall(map_data))
		error("There's a way out into space!");
	if (map_data->count_player > 1)
		error("I met a doppelganger.");
	if (map_data->count_player < 1)
		error("The player disappeared somewhere.");
	if (map_data->count_coin <= 0)
		error("I became a beggar.");
	if (map_data->count_exit > 1)
		error("I don't know which exit to go to.");
	if (map_data->count_exit < 1)
		error("Help me. There's someone here.");
}

t_map_data	*load_map(int argc, char *argv[])
{
	t_map_data	*map_data;

	if (argc != 2)
		error("I only need one parameter.");
	map_data = (t_map_data *)malloc(sizeof(t_map_data));
	if (!map_data)
		error("malloc assignment failed.");
	ft_memset(map_data, 0, sizeof(t_map_data));
	read_map(map_data, argv);
	get_map(argv, map_data);
	check_map_error(map_data);
	return (map_data);
}
