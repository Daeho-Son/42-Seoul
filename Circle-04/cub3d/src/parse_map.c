/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:18:52 by dason             #+#    #+#             */
/*   Updated: 2022/02/05 14:44:58 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	check_param(int argc, char *filepath)
{
	char	*extension;

	if (argc != 2)
		error_exit("Invalid parameters.");
	extension = ft_strrchr(filepath, '.');
	if (extension == NULL)
		error_exit("It's an incorrect extension.");
	if (ft_strncmp(".cub", extension, 5) != 0)
		error_exit("It's an incorrect extension.");
}

void	parse_map(int argc, char **argv, t_info *info)
{
	char	**tmp_file_data;

	ft_memset(&info->map_info, 0, sizeof(t_map));
	check_param(argc, argv[1]);
	tmp_file_data = store_file_data(argv[1]);
	get_file_data(info, tmp_file_data);
	get_map(info, tmp_file_data);
	free_double_pointer(&tmp_file_data);
}
