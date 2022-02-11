/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:57:45 by dason             #+#    #+#             */
/*   Updated: 2022/01/13 13:57:59 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

# include <stdbool.h>

void	error_exit(char *error_msg);
bool	is_type_id(char *type_id);
int		get_kind_of_type(char *type_id);

#endif
