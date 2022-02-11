/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_file_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:01:40 by dason             #+#    #+#             */
/*   Updated: 2022/02/05 14:39:37 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	check_num_of_type_id(char **tmp_file_data)
{
	char	**split;
	int		type_count;
	int		i;
	int		kind_of_type;

	type_count = 0;
	i = -1;
	while (tmp_file_data[++i])
	{
		split = ft_split(tmp_file_data[i], ' ');
		kind_of_type = get_kind_of_type(split[0]);
		if (kind_of_type != TYPE_MAP && kind_of_type != TYPE_NONE)
			type_count++;
		free_double_pointer(&split);
	}
	if (type_count > 6)
		error_exit("There are too many types.");
}

static void	check_file_data(t_info *info)
{
	t_map	map_info;

	map_info = info->map_info;
	if (map_info.no_texture == NULL)
		error_exit("The north texture file does not exist.");
	if (map_info.so_texture == NULL)
		error_exit("The south texture file does not exist.");
	if (map_info.we_texture == NULL)
		error_exit("The west texture file does not exist.");
	if (map_info.ea_texture == NULL)
		error_exit("The east texture file does not exist.");
	if (map_info.floor_color == 0)
		error_exit("Invalid floor rgb value.");
	if (map_info.ceiling_color == 0)
		error_exit("Invalid ceiling rgb value.");
	if (map_info.map_width == 0)
		error_exit("Invalid map size.");
	if (map_info.map_height == 0)
		error_exit("Invalid map size.");
}

void	get_file_data(t_info *info, char **tmp_file_data)
{
	char	**type_line;
	int		type_count;
	int		i;

	check_num_of_type_id(tmp_file_data);
	type_count = 0;
	i = -1;
	while (tmp_file_data[++i])
	{
		if (tmp_file_data[i][0] == '\0')
			continue ;
		type_line = ft_split(tmp_file_data[i], ' ');
		if (is_type_id(type_line[0]) == false)
			error_exit("Invalid type identifier.");
		get_type_data(info, type_line, get_kind_of_type(type_line[0]));
		free_double_pointer(&type_line);
		if (++type_count == 6)
			break ;
	}
	get_map_data(info, tmp_file_data);
	check_file_data(info);
}
