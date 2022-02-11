/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:27:18 by dason             #+#    #+#             */
/*   Updated: 2022/01/03 15:03:15 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/includes/libft.h"
# include "mlx.h"
# include "info.h"
# include <stdio.h>
# include <stdlib.h>

void	free_double_pointer(char ***s);
void	free_info(t_info *info);

#endif
