/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_move2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:14:22 by dason             #+#    #+#             */
/*   Updated: 2021/10/04 20:19:51 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	movement(t_info *info)
{
	info->move_count++;
	ft_putstr_fd("움직인 횟수: ", 1);
	ft_putnbr_fd(info->move_count, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
