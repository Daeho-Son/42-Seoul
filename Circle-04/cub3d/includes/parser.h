/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:18:59 by dason             #+#    #+#             */
/*   Updated: 2022/02/05 14:41:03 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include "get_next_line.h"
# include "parser_utils.h"
# include "info.h"
# include "utils.h"
# include "img.h"
# include <stdio.h>
# include <fcntl.h>

# define TYPE_NONE 0
# define TYPE_NO 1
# define TYPE_SO 2
# define TYPE_WE 3
# define TYPE_EA 4
# define TYPE_F 5
# define TYPE_C 6
# define TYPE_MAP 7

void	parse_map(int argc, char **argv, t_info *info);
char	**store_file_data(char *filepath);
void	get_file_data(t_info *info, char **tmp_file_data);
void	check_type_data(char **map_type, int type_id);
void	check_type_data_texture(char **map_type);
void	check_type_data_fc(char **map_type);
void	get_type_data(t_info *info, char **map_type, int type_id);
void	get_map_data(t_info *info, char **tmp_file_data);
void	get_map(t_info *info, char **tmp_file_data);

#endif
